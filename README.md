# Tool Kit for CivetWeb

A toolkit to simplify development with CivetWeb, reducing repetitive code by providing reusable functions for common tasks like JSON responses and HTTP handling.

## Functions

### `http_json_response`

Generates an HTTP response with a JSON body.

```c
const char *http_json_response(const char *status_code, const char *json);
```

- **Parameters**
  - `status_code`: The HTTP status code (e.g., "200 OK").
  - `json`: The JSON string to send in the response body.
- **Returns**: A dynamically allocated string containing the complete HTTP response.

### `http_text_response`

Generates an HTTP response with a plain text body.

```c
const char *http_text_response(const char *status, const char *text);
```

- **Parameters**
  - `status_code`: The HTTP status code (e.g., "200 OK").
  - `json`: The plain text to send in the response body.
- **Returns**: A dynamically allocated string containing the complete HTTP response.

### `http_error_response`

Generates an error response in JSON format with an error message.

```c
const char *http_error_response(const char *status_code, const char *message);
```

- **Parameters**
  - `status_code`: The HTTP status code (e.g., "400 Bad Request").
  - `json`: The error message to include in the response.
- **Returns**: A dynamically allocated string containing the error response.

## Notes

- All functions return a dynamically allocated string, so make sure to `free` the memory when you're done with the response.
- Designed to reduce repetitive code when working with **CivetWeb**.
