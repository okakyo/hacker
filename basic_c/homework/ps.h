#ifndef H_PS
#define H_PS

#define PI 3.141592653585793
#define E  2.718281828459045

// point->cm 変換係数  [cm] = [point]/PT2CM
#define PT2CM 28.35

typedef enum _iFont_ { 
            TIMES_ROMAN = 1,
            TIMES_BOLD,
            TIMES_ITALIC,
            TIMES_BOLDITALIC,
            HELVETICA,
            HELVETICA_BOLD,
            HELVETICA_OBLIQUE,
            HELVETICA_BOLDOBLIQUE,
            COURIER,
            COURIER_BOLD,
            COURIER_OBLIQUE,
            COURIER_BOLDOBLIQUE,
            SYMBOL
        }iFont;
#ifdef FONTTABLE
const char *fonttbl[] =
        {   "",
            "Times-Roman",
            "Times-Bold",
            "Times-Italic",
            "Times-BoldItalic",
            "Helvetica",
            "Helvetica-Bold",
            "Helvetica-Oblique",
            "Helvetica-BoldOblique",
            "Courier",
            "Courier-Bold",
            "Courier-Oblique",
            "Courier-BoldOblique",
            "Symbol"
        };
#endif
typedef enum _iLinety_ {
            SOLID=1,
            DOTTED,
            DASHED,
            CHAIN_DASHED }iLinety;

typedef enum _iPen_ {
            LINETO = 2,
            MOVETO }iPen;

typedef enum _lbalign_ {
            LEFT = -2,
            BELOW = -1,
            ABOVE = 1,  //BELOWと反対符号
            RIGHT = 2,  //LEFT と反対符号
            LEFTABOVE,
            LEFTBELOW,
            RIGHTBELOW,
            RIGHTABOVE }lbAlign;

// 初期設定
void init(void);
void init_ext(const char *of);

// 出力ファイルの変更
void ch_of(const char *of);

iFont get_ichar();
iFont get_fntsize();

double get_Xsize();
double get_Ysize();
double get_nwidth();
double get_nhight();

void viewport(double, double, double, double);
void xyworld(double, double, double, double);
void fin(void);
void linety(int);
void linewidth(double);
void setgray(double);
void setrgb(double, double, double);
void newpath(void);
void fill(void);
void closepath(void);
void stroke(void);
void rotate(int);
void scale(double, double);

// 線属性を設定
void set_line_gwt(double g, double w, int it);
// Defaultの線属性を設定
void default_line_gwt();

// 世界座標 -> 正規座標
double x_w2n(double x);
double y_w2n(double y);
// 世界座標 -> 用紙座標
double x_w2paper(double x);
double y_w2paper(double y);

// 正規座標 -> 世界座標 
double x_n2w(double xn);
double y_n2w(double yn);

void transrate(double, double);
void clipon(double, double, double, double);
void eoclipon(double, double, double, double);
void clipoff(void);
void plot(double x, double y, int ipen);

// 座標値を使用せず、point単位を使って現在位置から相対移動
void rmoveto(double xp, double yp);

void plotseries(double xx[], double yy[], int n, double g, double w, int it);
void plotseries1(double xx[], double yy[], int n);

void line(double, double, double, double, double, double, int);
void line1(double, double, double, double);
void rect(double, double, double, double, double, double, int);
void rect1(double, double, double, double);
void rectfill1(double, double, double, double);
void circ(double, double, double, double, double, int);
void circ1(double, double, double);
void circfill1(double, double, double);

// 半径は座標系とは関係なくmm単位で与える
void marker_circ1(double x1, double y1, double r_mm, int fill_flag);

// (x1,y1), (x2,y2) を対角頂点とし、 nrow行, ncol列の格子を描く
void grid(double x1, double y1, double x2, double y2, int nrow, int ncol);
// nrow行, ncol列の格子位置に文字列を書き込む (格子線は描かない)
void grid_with_text(double x1, double y1, double x2, double y2, int nrow, int ncol, char *str);

void ellipse(double, double, double, double, double, double, int);
void ellipse1(double, double, double, double);
void ellipsefill1(double, double, double, double);
void arc(double, double, double, double, double, double, double, int);
void arc1(double, double, double, double, double);
void curv(double, double, double, double,
                 double, double, double, double, double, double, int);
void curv1(double, double, double, double, double, double, double, double);
void triangl(double, double, double, double, double, double, int);
void triangl1(double, double, double, double);
void trianglfill1(double, double, double, double);
void spline(double, double, double, double,
                   double, double, double, double, int, double, double);
void spline1(double, double, double, double, double, double, double, double, int);
void parabola(double, double, double, double, double, double, double, double, int);
void parabola1(double, double, double, double, double, double);
void arrow(double, double, double, double, double, double, double);
void arrow1(double, double, double, double, double);

void arrow01(double x1, double y1, double x2, double y2, double d,
                    double g, double w);
void arrow11(double x1, double y1, double x2, double y2, double d);

void resist(double, double, double, double, double, double); 
void battery(double, double, double, double, double, double);
void coil(double, double, double, double, double, int, double);

/* 文字列 */
void show_text(char* str);
void text(double, double, int, char* );
// 一文字の書き込み
void write_char(double x, double y, char c);

void textx(double, double, int, char* );
void texty(double, double, int, char* );
void offset_wrt_line(lbAlign a, int ftsize, int n, double *xs, double *ys);
void textsft(int ftsize, lbAlign a, double x, double y, int n, char* str);

// 上付き文字 [str]^sup
void textsup(char *sup);

// 下付き文字 [str]_sub
void textsub(char *sub);

void setchar(int font, int fontsize);
void resetchar();

void square(double, double);

#endif
