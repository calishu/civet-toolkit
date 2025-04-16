/*
Copyright (c) 2025 calishu
This software is licensed under the MIT License, check the LICENSE file for more information.
*/

#include <stdio.h>


// http responses

const char *http_json_response(const char *status_code, const char *json) {
    size_t buffer_size = strlen(json) + 256;
    char *buffer = malloc(buffer_size);

    if (!buffer) { return NULL; }

    snprintf(buffer, buffer_size,
            "HTTP/1.1 %s\r\n"
            "Content-Type: application/json\r\n"
            "Content-Lenght: %lu\r\n\r\n"
            "%s", status_code, strlen(json), json);

    return buffer;
}

const char *http_text_response(const char *status, const char *text) {
    size_t buffer_size = strlen(text) + 256;
    char *buffer = malloc(buffer_size);

    if (!buffer) { return NULL; }

    snprintf(buffer, buffer_size,
            "HTTP/1.1 %s\r\n"
            "Content-Type: text/plain; charset=UTF-8\r\n"
            "Content-Lenght: %lu\r\n\r\n"
            "%s", status_code, strlen(text), text);
    
    return buffer;
}

const char *http_error_response(const char *status_code, const char *message) {
    size_t body_size = strlen(message) + 64;
    char *body = malloc(body_size);
    if (!body) { return NULL; }

    snprintf(body, body_size, "{ \"error\": \"%s\" }", message);

    size_t response_size = strlen(body) + strlen(status_code) + 256;
    char *response = malloc(response_size);
    if (!response) {
        free(body);
        return NULL;
    }

    snprintf(response, response_size,
             "HTTP/1.1 %s\r\n"
             "Content-Type: application/json\r\n"
             "Content-Length: %zu\r\n\r\n"
             "%s",
             status_code, strlen(body), body);

    free(body);
    return response;
}
