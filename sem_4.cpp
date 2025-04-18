#include <vector>
#include <utility> // ��� std::pair
#include <cmath>   // ��� std::hypot

class Polyline {
private:
    std::vector<std::pair<double, double>> points;

public:
    // ����������� � ��������� ������
    Polyline(double x, double y) {
        points.emplace_back(x, y);
    }

    // ����������
    ~Polyline() = default;

    // �������� ����� � �������
    void addPoint(double x, double y) {
        points.emplace_back(x, y);
    }

    // �������� ���������� �����
    unsigned int getNumberOfPoints() const {
        return points.size();
    }

    // �������� ����� �������
    double getLength() const {
        double length = 0.0;
        for (size_t i = 1; i < points.size(); ++i) {
            double dx = points[i].first - points[i-1].first;
            double dy = points[i].second - points[i-1].second;
            length += std::hypot(dx, dy);
        }
        return length;
    }

    // �������� x-���������� i-�� �����
    double getX(unsigned int i) const {
        return points[i].first;
    }

    // �������� y-���������� i-�� �����
    double getY(unsigned int i) const {
        return points[i].second;
    }
};
