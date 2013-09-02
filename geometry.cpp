#include "geometry.hh"

Ray::Ray(Point3f origin, Vector3f direction) 
  : origin(origin), direction(direction)
{
}

Sphere::Sphere(Point3f center, float radius) 
  : center_(center), radius_(radius)
{
}

float Sphere::intersection(Ray ray) {
  /* Ray-sphere intersection formula
   * Many resources available on this; e.g. 
   * <http://wiki.cgsociety.org/index.php/Ray_Sphere_Intersection>
   */
  Vector3f d = ray.direction;
  Point3f e = ray.origin;
  Point3f c = center_;

  float determinant = square(d.dot(e - c)) - (d.dot(d))*((e - c).dot(e - c) - square(radius_));
  if (determinant < 0) { return -1; }

  // negative determinant
  float tn = (-d.dot(e-c) - sqrt(determinant)) / (d.dot(d));
  if (tn > 0) { return tn; }

  // positive determinant
  float tp = (-d.dot(e-c) + sqrt(determinant)) / (d.dot(d));
  if (tp > 0) { return tp; }

  return -1;
}