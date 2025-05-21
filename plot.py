#!/usr/bin/env python3
import matplotlib.pyplot as plt
import sys

data_file = sys.argv[1]  # Имя файла данных
output_file = sys.argv[2]  # Имя файла графика

# Читаем данные из файла
x = []
y = []
with open(data_file, 'r') as f:
    for line in f:
        xi, yi = map(float, line.split())
        x.append(xi)
        y.append(yi)

# Строим график
plt.plot(x, y)
plt.xlabel('X')
plt.ylabel('Y')
plt.title('График данных из ' + data_file)
plt.savefig(output_file) # Сохраняем график в файл
plt.close()
