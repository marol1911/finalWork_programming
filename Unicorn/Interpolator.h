//
//  Interpolator.h
//  Prototype_1
//
//  Created by Nathan on 2012-12-31.
//  Copyright (c) 2012 Nathan. All rights reserved.
//

#ifndef __Prototype_1__Interpolator__
#define __Prototype_1__Interpolator__

#include <iostream>
#include <cmath>

namespace unicorn {

    class Interpolator {
    public:
        static double Linear(double a, double b, double x);
        static double Cosinus(double a, double b, double x);
        static double Cubic(double y0, double y1, double y2, double y3, double x);
        
        static double Linear2D(double a, double b, double c, double d, double x, double y);
        static double Cosinus2D(double a, double b, double c, double d, double x, double y);
        static double Cubic2D(double y0,  double y1,  double y2,   double y3,
                              double y10, double y11, double y12, double y13,
                              double y20, double y21, double y22, double y23,
                              double y30, double y31, double y32, double y33,
                              double x,   double y);
        
        static double Linear3D(double a, double b, double c, double d, double e, double f, double g, double h, double x, double y, double z);
        static double Cosinus3D(double a, double b, double c, double d, double e, double f, double g, double h, double x, double y, double z);
    };
};
#endif /* defined(__Prototype_1__Interpolator__) */
