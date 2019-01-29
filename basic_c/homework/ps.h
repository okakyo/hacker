#ifndef H_PS
#define H_PS

#define PI 3.141592653585793
#define E  2.718281828459045

// point->cm �ϊ��W��  [cm] = [point]/PT2CM
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
            ABOVE = 1,  //BELOW�Ɣ��Ε���
            RIGHT = 2,  //LEFT �Ɣ��Ε���
            LEFTABOVE,
            LEFTBELOW,
            RIGHTBELOW,
            RIGHTABOVE }lbAlign;

// �����ݒ�
void init(void);
void init_ext(const char *of);

// �o�̓t�@�C���̕ύX
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

// ��������ݒ�
void set_line_gwt(double g, double w, int it);
// Default�̐�������ݒ�
void default_line_gwt();

// ���E���W -> ���K���W
double x_w2n(double x);
double y_w2n(double y);
// ���E���W -> �p�����W
double x_w2paper(double x);
double y_w2paper(double y);

// ���K���W -> ���E���W 
double x_n2w(double xn);
double y_n2w(double yn);

void transrate(double, double);
void clipon(double, double, double, double);
void eoclipon(double, double, double, double);
void clipoff(void);
void plot(double x, double y, int ipen);

// ���W�l���g�p�����Apoint�P�ʂ��g���Č��݈ʒu���瑊�Έړ�
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

// ���a�͍��W�n�Ƃ͊֌W�Ȃ�mm�P�ʂŗ^����
void marker_circ1(double x1, double y1, double r_mm, int fill_flag);

// (x1,y1), (x2,y2) ��Ίp���_�Ƃ��A nrow�s, ncol��̊i�q��`��
void grid(double x1, double y1, double x2, double y2, int nrow, int ncol);
// nrow�s, ncol��̊i�q�ʒu�ɕ�������������� (�i�q���͕`���Ȃ�)
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

/* ������ */
void show_text(char* str);
void text(double, double, int, char* );
// �ꕶ���̏�������
void write_char(double x, double y, char c);

void textx(double, double, int, char* );
void texty(double, double, int, char* );
void offset_wrt_line(lbAlign a, int ftsize, int n, double *xs, double *ys);
void textsft(int ftsize, lbAlign a, double x, double y, int n, char* str);

// ��t������ [str]^sup
void textsup(char *sup);

// ���t������ [str]_sub
void textsub(char *sub);

void setchar(int font, int fontsize);
void resetchar();

void square(double, double);

#endif
