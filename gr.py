import matplotlib.pyplot as plt
import time

def dda(x1, x2, y1, y2):
  dx = x2 - x1
  dy = y2 - y1
  steps = int(max(abs(dx), abs(dy)))

  x_inc = dx / steps
  y_inc = dy / steps

  x = x1
  y = y1
  
  x_points = []
  y_points = []

  for i in range(steps + 1):
    x_points.append(round(x))
    y_points.append(round(y))
    x += x_inc
    y += y_inc

  return x_points, y_points

def animateLine(x1, x2, y1, y2):
  x_points, y_points = dda(x1, x2, y1, y2)
  plt.ion()
  fig, ax = plt.subplots()
  ax.set_xlim(min(x1, x2) - 2, min(x1, x2) + 2)
  ax.set_ylim(min(y1, y2) - 2, min(y1, y2) + 2)
  ax.set_aspect('equal')
  ax.grid(True)

  line, = ax.plot([], [], 'ro-')

  for i in range(len(x_points)):
    line.set_data(x_points[:i+1], y_points[:i+1])
    plt.draw()
    plt.pause(1)

  plt.ioff()
  plt.show()

animateLine(2, -5, -2, 4)
