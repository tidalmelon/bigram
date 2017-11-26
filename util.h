#ifndef _UTIL_H
#define _UTIL_H

int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);

int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

int decode(std::string& line, std::string& outline, char encoding[]);

#endif
