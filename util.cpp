#include<string>
#include<iostream>
#include<iconv.h>
#include<string.h>

int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen) {
    iconv_t cd;
    int rc;
    char *pin = inbuf;
    char *pout = outbuf;
    size_t inlen_ = strlen(pin);

    cd = iconv_open(to_charset, from_charset);
    if (cd == 0) {
        return -1;
    }
    memset(outbuf, 0, outlen);
    if (iconv(cd, &pin, &inlen, &pout, &outlen) == -1) {
        return -1;
    }
    iconv_close(cd);
    return 0;
}

int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen, char encoding[]) {
    char to_charset[] = "utf-8";
    return code_convert(encoding, to_charset, inbuf, inlen, outbuf, outlen);
}

int decode(std::string& line, std::string& outline, char encoding[]) {
    char *inbuf = (char *)line.c_str();
    size_t inlen = strlen(inbuf);

    char outbuf[200];
    size_t outlen = 200;

    iconv_t cd;
    int rc;
    char *pin = inbuf;
    char *pout = outbuf;

    char to_charset[] = "utf-8";
    char from_charset[] = "GBK";
    cd = iconv_open(to_charset, from_charset);
    if (cd == 0) {
        return -1;
    }
    memset(outbuf, 0, outlen);
    if (iconv(cd, &pin, &inlen, &pout, &outlen) == -1) {
        return -1;
    }
    outline = outbuf;
    iconv_close(cd);
    return 0;
}


