#include <iostream>
#include <string>
#include <math.h>
# define PI           3.14159265358979323846
using namespace std;

class Point{
    double x, y;
    friend std::ostream& operator<< (ostream &out, const Point& point);
    friend std::istream& operator>> (istream &in, Point &point);
public:
    Point(double x, double y) : x(x), y(y){};

    double getX() const{return x;};
    double getY() const{return y;};
};

std::istream& operator>> (std::istream &in, Point& point){
    in >> point.x >> point.y;
    return in;
}


std::ostream& operator<< (std::ostream &out, const Point &point){
    out << "Point(" << point.x << ", " << point.y << ")" << endl;
    return out;
}

enum Color{ Red, Green, Blue, None};
std::istream& operator>>(std::istream& is, Color& f)
{
    std::string s;
    is >> s;
    if (s == "Red") f = Color::Red;
    else if (s=="Green") f= Color::Green;
    else if (s=="Blue") f= Color::Blue;
    else if (s=="None") f= Color::None;
    return is;
}

std::ostream& operator<< (std::ostream &out, const Color& f){
    int n = f;
    string ColorString[]{"Red", "Green", "Blue", "None"};
    out << ColorString[n] << std::endl;
    return out;
}

class Figure{
    Point center;
    Color color;
public:
    Figure(Point& center, Color& color) : center(center), color(color) {};;
    double getCenterX(){return center.getX();};
    double getCenterY(){return center.getY();};
    void outColor(){
        cout << "Color: " <<  color << endl;
    }

};

class Circle : public Figure{
    double radius;

public:
    Circle(Point center, Color& color, double& radius) : Figure(center, color), radius(radius){};

    void Square(){
        cout << "The square is " << PI*radius*radius << endl;
    };


    void DescribingRectangleFunction(){

        Point p1(getCenterX() - radius, getCenterY() + radius);
        Point p2(getCenterX() + radius, getCenterY() + radius);
        Point p3(getCenterX() + radius, getCenterY() - radius);
        Point p4(getCenterX() - radius, getCenterY() - radius);


        cout << "Describing Rectangle : " << endl;
        cout << p1 << p2 << p3 << p4;

    };
};



//class Figure_ : public Figure{
//
//protected:
//    double edge_length;
//public:
//    Figure_(Point& center, Color& color, double& edge_length) : Figure(center, color), edge_length(edge_length){};
//};

class Square : public Figure{
private:
            double edge_length;

public:
    Square(Point& center, Color& color, double& edge_length) : Figure(center, color){
        this->edge_length =  edge_length;;
    };

    void SquareS(){
        cout << "The square is " << edge_length*edge_length << endl;
    };

    void DescribingRectangleFunction(){

        double radius = edge_length / 2;
        Point p1(getCenterX() - radius, getCenterY() + radius);
        Point p2(getCenterX() + radius, getCenterY() + radius);
        Point p3(getCenterX() + radius, getCenterY() - radius);
        Point p4(getCenterX() - radius, getCenterY() - radius);


        cout << "Describing Rectangle : " << endl;
        cout << p1 << p2 << p3 << p4;
    };
};

class Triangle : public Figure{
    double edge_length;
public:
    Triangle(Point& center, Color& color, double& edge_length) : Figure(center, color){
        this->edge_length =  edge_length;
    };

    void SquareS(){
        cout << "The square is " << sqrt(3)/4*edge_length*edge_length << endl;
    };

    void DescribingRectangleFunction(){

        double radius = edge_length / sqrt(3);
        Point p1(getCenterX() - radius, getCenterY() + radius);
        Point p2(getCenterX() + radius, getCenterY() + radius);
        Point p3(getCenterX() + radius, getCenterY() - radius);
        Point p4(getCenterX() - radius, getCenterY() - radius);


        cout << "Describing Rectangle : " << endl;
        cout << p1 << p2 << p3 << p4;
    };

};

class Rectangle : public Figure{
    double width;
    double height;

public:
    Rectangle(Point& center, Color& color, double& width, double& height) : Figure(center, color), width(width), height(height){};

    void SquareS(){
        cout << "The square is " << width*height << endl;
    };

    void DescribingRectangleFunction(){

        double radius = sqrt(width*width + height*height);


        Point p1(getCenterX() - radius, getCenterY() + radius);
        Point p2(getCenterX() + radius, getCenterY() + radius);
        Point p3(getCenterX() + radius, getCenterY() - radius);
        Point p4(getCenterX() - radius, getCenterY() - radius);



        cout << "Describing Rectangle : " << endl;
        cout << p1 << p2 << p3 << p4;
    };
};

int main(){

    Color colorIn;
    double x, y;

    double edge_length;



    string figureName;
    cout << "Input the Figure: ";
    cin >> figureName;
    if (figureName == "circle") {
        cin >> x >> y;
        Point pointIn(x, y);
        cout << pointIn;
        cin >> colorIn;
        double radiusIn;
        cin >> radiusIn;
        auto *circle = new Circle(pointIn, colorIn, radiusIn);
        circle->Square();
        circle->DescribingRectangleFunction();
        circle->outColor();
        delete circle;
    }

    else if (figureName == "square") {
        cin >> x >> y;
        Point pointIn(x, y);
        cout << pointIn;
        cin >> colorIn;
        cin >> edge_length;
        Square* square = new Square(pointIn, colorIn, edge_length);
        square->SquareS();
        square->DescribingRectangleFunction();
        square->outColor();
        delete square;
    }

    else if (figureName == "triangle"){
        cin >> x >> y;
        Point pointIn(x, y);
        cout << pointIn;
        cin >> colorIn;
        cin >> edge_length;
        Triangle* triangle = new Triangle(pointIn, colorIn, edge_length);
        triangle->SquareS();
        triangle->DescribingRectangleFunction();
        triangle->outColor();
        delete triangle;
    }

    else if (figureName == "Rectangle"){
        cin >> x >> y;
        Point pointIn(x, y);
        cout << pointIn;
        cin >> colorIn;
        double width, height;
        cin >> width >> height;
      
        Rectangle* rectangle = new Rectangle(pointIn, colorIn, width, height);
        rectangle->SquareS();
        rectangle->DescribingRectangleFunction();
        rectangle->outColor();
        delete rectangle;
    }
    else cout << "Error!";


}
