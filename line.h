struct color{
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

struct pic{
  struct color data[2048][2048];
};

void drawLine(struct pic* p, int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);
void drawPic(struct pic* p, char* fileName, int width, int height);
