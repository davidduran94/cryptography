unsigned char CTR(unsigned char nonce, unsigned char counter, unsigned char m, Key K);

unsigned char CBC(unsigned char iv, unsigned char m, unsigned char mode, Key K);

unsigned char ECB(unsigned char m, unsigned char mode, Key K);

unsigned char OFB(unsigned char iv, unsigned char mode, Key K);

unsigned char CFB(unsigned char iv, unsigned char m, unsigned char mode, Key K);

void CIPHERFILE(const char *Source, const char *Target, const char *Mode ,Key key);