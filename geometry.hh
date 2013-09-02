#pragma once

#include "util.hh"

class Ray {
public:
  Ray(Point3f origin, Vector3f direction);
  Point3f origin;
  Vector3f direction;
};

class Object {
public:
  // returns time value of intersection; returns -ve value if no intersection
  virtual float intersection(Ray ray) = 0;
};

class Sphere : Object {
public:
  Sphere(Point3f center, float radius);
  virtual float intersection(Ray ray);

private:
  Point3f center_;
  float radius_;
};