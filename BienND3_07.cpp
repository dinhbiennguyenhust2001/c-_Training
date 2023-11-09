#include <iostream>
#include <vector>
#include <windows.h>

class CShape
{
private:
	int color;
public:
	CShape(int color) : color(color) {}
	~CShape() {}
	virtual void draw(int x, int y) = 0;
	int get_color()
	{
		return color;
	}
};

class CLine : public CShape
{
private:
	int length;
public:
	CLine(int color, int length) : CShape(color), length(length) {};
	~CLine() {}
	void draw(int x, int y)
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);
		HPEN pen = CreatePen(PS_SOLID, 5, RGB(get_color(), 0, 0));
		SelectObject(device_context, pen);
		MoveToEx(device_context, x, y, NULL);
		LineTo(device_context, x + length, y);
		ReleaseDC(console_handle, device_context);
	}
};

class CCircle : public CShape
{
private:
	int radium;
public:
	CCircle(int color, int radium) : CShape(color), radium(radium) {}
	~CCircle() {}
	void draw(int x, int y)
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);
		HPEN pen = CreatePen(PS_SOLID, 5, RGB(get_color(), 0, 0));
		SelectObject(device_context, pen);
		Ellipse(device_context, x - radium, y - radium, x + radium, y + radium);
		ReleaseDC(console_handle, device_context);
	}
};

class CRectangle : public CShape
{
private:
	int width;
	int length;
public:
	CRectangle(int color, int width, int length) : CShape(color), width(width), length(length) {}
	~CRectangle() {}
	void draw(int x, int y)
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);
		HPEN pen = CreatePen(PS_SOLID, 5, RGB(get_color(), 0, 0));
		SelectObject(device_context, pen);
		Rectangle(device_context, x - length , y - width, x + length, y +width);
		ReleaseDC(console_handle, device_context);
	}
	int get_width()
	{
		return width;
	}
};

class CSquare : public CRectangle
{
public:
	CSquare(int color, int width) : CRectangle(color, width, width) {}
	~CSquare() {}
	void draw(int x, int y)
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);
		HPEN pen = CreatePen(PS_SOLID, 5, RGB(get_color(), 0, 0));
		SelectObject(device_context, pen);
		Rectangle(device_context, x - get_width(), y - get_width(), x + get_width(), y + get_width());
		ReleaseDC(console_handle, device_context);
	}
};

class CPicture {
private:
    std::vector<CShape*> shapes;  // Vector lưu trữ các con trỏ trỏ đến CShape
public:
    ~CPicture() {}

    void addShape(CShape* shape) {
        shapes.push_back(shape);
    }

    void draw() {
        for (CShape* shape : shapes) {
            shape->draw(0, 0);  // Giả sử vẽ tất cả các hình tại điểm gốc (0,0)
        }
    }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    CPicture picture;
    // Giả sử các màu sắc và kích thước được định trước
    CLine *line = new CLine(255, 100);  // Red line, 100 pixels long
    CCircle *circle = new CCircle(255, 50);  // Red circle, radius 50 pixels
    CRectangle *rectangle = new CRectangle(255, 100, 200);  // Red rectangle, 100x200 pixels
    CSquare *square = new CSquare(255, 100);  // Red square, 100x100 pixels

    picture.addShape(line);
    picture.addShape(circle);
    picture.addShape(rectangle);
    picture.addShape(square);
    
    picture.draw();

    return 0;
}