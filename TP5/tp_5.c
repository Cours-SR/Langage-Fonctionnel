#include <asm-generic/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include<stdbool.h>

//Je suis à la 5.2
// Vérifier free car là c'est un enfer

typedef struct socket_config{
	struct sockaddr_in address;
	int protocole;
	int type;
	int port;
	int nb_max_co;
}socket_config;

typedef struct couple{
	char* key;
	char* value;
}couple;


typedef struct http_request{
	char* route;
	//liste de structure contenant les couples clé/valeur
	couple* params;
}http_request;

typedef struct pixel{
	int x;
	int y;
	char* color;
}pixel;

pixel* pixels;
http_request req;


char* read_file(char* path){
    char * buffer;
    FILE * f = fopen (path, "rb");
    if (f)
    {
       // déplace le curseur jusqu’au charactère représentant la fin du fichier
        fseek (f, 0, SEEK_END);
        long length = ftell (f); // ftell renvoie la position du curseur
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
        }
        fclose (f);
    } else {
        printf("file not oppened : %s\n", path);
    }
    return buffer;
}

char* concat(const char* str1, const char* str2){
    int i = 0;
    int j = 0;
    while(str1[i] != '\0'){ //on va à la fin de str1
        i++;
    }
    while(str2[j] != '\0'){ //on va à la fin de str2
        j++;
    }

    char* result = (char*)malloc(i + j + 1); //alloue taille exacte
    
    strcpy(result, str1); // Copie contenu str1 dans result
    strcpy(result + i, str2); // Copie contenu str2 suite str1
	result[i + j] = '\0';

    // printf("%s\n", result);
    return result;
}

char** strsplit(char* base, char delim, int* len){

	*len = 1;
	for (int i = 0; base[i] != 0; i++){
		if (base[i] == delim){
			(*len)++;
		}
	}
	char** res = (char**) malloc(sizeof(char*) * (*len));
	res[0] = base;
	int current_res_len = 1;
	for (; current_res_len < (*len); base++){
		if (*base == delim){
			*base = 0;
			res[current_res_len] = base + 1;
			current_res_len++;
		}
	}
	return res;
}

char* extractLine(const char *buffer) {
    // Recherche de la première occurrence de "GET"
    const char *getRequestStart = strstr(buffer, "GET");
    if (getRequestStart) {
        // Trouver la fin de la ligne
        const char *getRequestEnd = strstr(getRequestStart, "\n");
        if (getRequestEnd) {
            int getRequestLength = getRequestEnd - getRequestStart;
            char *getRequestLine = (char*)malloc(getRequestLength + 1);
            strncpy(getRequestLine, getRequestStart, getRequestLength);
            getRequestLine[getRequestLength] = '\0';
            return getRequestLine;
        }
    }
    return NULL;
}

void divideMsg(const char* httpRequest){
	// const char *httpRequest = "GET /addUser/?name=bob&age=23&nickname=boby&nickname=boby&adress=ouiouiyaourt HTTP/1.1";
    int numComponents;
    char* httpRequestCopy = strdup(httpRequest);
	bool param;

    char** parts = strsplit(httpRequestCopy, ' ', &numComponents);
    // printf("Verbe: %s\n", parts[0]);   // Verbe = "GET"
    // printf("URL: %s\n", parts[1]);     // URL = "/addUser/?name=bob&age=23..."
    // printf("Protocole version : %s\n", parts[2]); // Protocole = "HTTP/1.1"
	
	// printf("parts[1]: %s\n", parts[1]);
	if(strstr(parts[1], "?") == NULL){
		param = false;
	}
	else{
		param = true;
	}

	char** urlParts = strsplit(parts[1], '/', &numComponents);
	// printf("Adresse: %s//%s\n", urlParts[0], urlParts[2]); // Adresse = "http://localhost:7070"
	// printf("Route: %s\n", urlParts[1]);  // Route = "addUser"
	
	req.route = strdup(urlParts[1]);
	// printf("route: %s\n", req.route);
	
	if(param == false){
		req.params = NULL;
		return;
	}
	
	// printf("Paramètres: %s\n", urlParts[2]); // Paramètres = "?name=bob&age=23"
	char* parameters = urlParts[2]; // Parameters = "?name=bob&age=23&..."
    char** paramPairs = strsplit(parameters, '&', &numComponents);
	int nb = numComponents;
    req.params = (couple*)malloc(numComponents * sizeof(couple));

    for (int i = 0; i < nb; i++) {
        char** keyValue = strsplit(paramPairs[i], '=', &numComponents);
        req.params[i].key = strdup(keyValue[0]);
		// printf("key: %s\n", req.params[i].key);
        req.params[i].value = strdup(keyValue[1]);
		// printf("value: %s\n", req.params[i].value);
        free(keyValue);
    }
	req.params[0].key = req.params[0].key + sizeof(char);

    free(paramPairs);
	free(urlParts);
    free(parts);
    free(httpRequestCopy);
}

pixel add_pixel(int x, int y, char* color){
	//créer pixel
	pixel new_pixel;
    new_pixel.x = x;
    new_pixel.y = y;

	//color = %23ff0000
	//on enlève le %23
	color = color + 3;
    new_pixel.color = (char*)malloc(strlen(color) + 4);
    strcpy(new_pixel.color, "#");
    strcat(new_pixel.color, color);
	new_pixel.color[strlen(color) + 1] = '\0';

    // Resize the array and add the new pixel.
    if (pixels == NULL) {
        pixels = (pixel*)malloc(sizeof(pixel));
    } else {
        pixels = (pixel*)realloc(pixels, sizeof(pixel) * (sizeof(pixels) / sizeof(pixel) + 1));
    }
	pixels[(sizeof(pixels) / sizeof(pixel))] = new_pixel;
	
	return new_pixel;
}

void get_pixels(int socketNV, pixel* pixels){
	if(pixels == NULL){
		return;
	}
	//créer json
	char* json = "[";
	json = concat(json, "{\"x\":");
	char* x = malloc(sizeof(char) * 10);

	snprintf(x, 10, "%d", pixels[0].x);
	json = concat(json, x);
	json = concat(json, ",\"y\":");
	char* y = malloc(sizeof(char) * 10);
	snprintf(y, 10, "%d", pixels[0].y);
	json = concat(json, y);
	json = concat(json, ",\"color\":\"");
	printf("color: %s\n", pixels[0].color);
	json = concat(json, pixels[0].color);
	json = concat(json, "\"}");
	//taille du tableau
	int taille = sizeof(pixels) / sizeof(pixel);
	for(int i = 1; i < taille; i++){
		json = concat(json, ",{\"x\":");
		char* x = malloc(sizeof(char) * 10);
		snprintf(x, 10, "%d", pixels[i].x);
		json = concat(json, x);
		json = concat(json, ",\"y\":");
		char* y = malloc(sizeof(char) * 10);
		snprintf(y, 10, "%d", pixels[i].y);
		json = concat(json, y);
		json = concat(json, ",\"color\":\"");
		json = concat(json, pixels[i].color);
		json = concat(json, "\"}");
	}
	json = concat(json, "]");
	printf("json: %s\n", json);
	char http_response[4096];
	snprintf(http_response, sizeof(http_response), "HTTP/1.1 200 OK\r\n"
									"Content-Type: application/json\r\n"
									"Access-Control-Allow-Origin: *\r\n"
									"\r\n"
									"%s\r\n",json);
	int e = send(socketNV, http_response, strlen(http_response), 0);	
}

void run_server(socket_config sock){
	// Créez la socket
	int numero_socket = socket(sock.protocole, sock.type, 0);

	int optname = SO_REUSEADDR | SO_REUSEPORT;
	int option_level = SOL_SOCKET;
	int opt = 1;
	setsockopt(numero_socket, option_level, optname, &opt, sizeof(opt));
	
	memset(&sock.address, 0, sizeof(sock.address));
    sock.address.sin_family = AF_INET;
    sock.address.sin_addr.s_addr = inet_addr("127.0.0.1");
    sock.address.sin_port = htons(sock.port);

	//Attache la socket à l'adresse précisée
	bind(numero_socket, (struct sockaddr*)&sock.address, sizeof(sock.address));
	// Demande à la socket d'écouter les connections
	listen(numero_socket, sock.nb_max_co);

	int addrlen = sizeof(sock.address);
	while(1){
		// Accepte une connection et affiche plusieurs connections
		int socketNV = accept(numero_socket, (struct sockaddr*)&sock.address, (socklen_t*)&addrlen);
		printf("Connection reçue, id de la nouvelle socket : %d\n", socketNV);

		// Recoit un message du client avec read
		char buffer[1024];
		int r = read(socketNV, buffer, 1024);

		//Récupère l'url
		char* msg = extractLine(buffer);
		divideMsg(msg);
		// printf("message: %s\n", msg);
		
		// Envoie message au client avec send et file
		char* file = NULL;
		file = read_file("home.html");
		if (req.route && strcmp(req.route, "home") == 0) {
			if(file){
				char http_response[4096];
				snprintf(http_response, sizeof(http_response), "HTTP/1.1 200 OK\r\n"
										"Content-Type: html\r\n"
										"\r\n"
										"%s\r\n", file);
				int e = send(socketNV, http_response, strlen(http_response), 0);
			}
		}
		else if(strcmp(req.route, "get_pixels") == 0){
			get_pixels(socketNV, pixels);
		}
		else if(strcmp(req.route, "add_pixel") == 0){
			add_pixel(atoi(req.params[0].value), atoi(req.params[1].value), req.params[2].value);
			//pixels[0].color
			printf("color: %s\n", pixels[0].color);
			get_pixels(socketNV, pixels);
		}
		else if(strcmp(req.route, "favicon.ico") == 0){

		}
		else{
			const char* http_response = "HTTP/1.1 404 Not Found\r\n"
										"Content-Type: html\r\n"
										"\r\n"
										"<html><body><h1>404 Not Found</h1><p>La page demandée n'existe pas</p></body></html>\r\n";
			int e = send(socketNV, http_response, strlen(http_response), 0);
		}
		close(socketNV);
		free(file);
	}
	shutdown(numero_socket, SHUT_RDWR);

	free(req.route);
	free(req.params);
	free(&sock.address);
}

int main(int argc, char const* argv[]){
	socket_config sock;
    sock.protocole = AF_INET;
    sock.type = SOCK_STREAM;
    sock.port = 7070;
    sock.nb_max_co = 3;

    run_server(sock);
	for (int i = 0; i < sizeof(pixels) / sizeof(pixel); i++) {
        free(pixels[i].color);
    }

    free(pixels);

    return 0;
}