#include <vector>
#include <utility> // для std::pair
#include <cmath>   // для std::hypot

class Polyline {
private:
    std::vector<std::pair<double, double>> points;

public:
    // Конструктор с начальной точкой
    Polyline(double x, double y) {
        points.emplace_back(x, y);
    }

    // Деструктор
    ~Polyline() = default;

    // Добавить точку в ломаную
    void addPoint(double x, double y) {
        points.emplace_back(x, y);
    }

    // Получить количество точек
    unsigned int getNumberOfPoints() const {
        return points.size();
    }

    // Получить длину ломаной
    double getLength() const {
        double length = 0.0;
        for (size_t i = 1; i < points.size(); ++i) {
            double dx = points[i].first - points[i-1].first;
            double dy = points[i].second - points[i-1].second;
            length += std::hypot(dx, dy);
        }
        return length;
    }

    // Получить x-координату i-ой точки
    double getX(unsigned int i) const {
        return points[i].first;
    }

    // Получить y-координату i-ой точки
    double getY(unsigned int i) const {
        return points[i].second;
    }
};
