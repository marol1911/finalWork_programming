//
//  Interpolator.cpp
//  Prototype_1
//
//  Created by Nathan on 2012-12-31.
//  Copyright (c) 2012 Nathan. All rights reserved.
//

#include "Interpolator.h"

namespace unicorn {
    // a = y du point 1
    // b = y du point 2
    // x = [0,1] 0 = point a et 1 au point b

    double Interpolator::Linear(double a, double b, double x) {
        return a * (1 - x) + b * x;
    }

    double Interpolator::Cosinus(double a, double b, double x) {
        double k = (1 - cos(3.1416 * x)) / 2;
    
        return Linear(a, b, k);
    }

    double Interpolator::Cubic(double y0, double y1, double y2, double y3, double x) {
        double a = y3 - y2 - y0 + y1;
        double b = y0 - y1 - a;
        double c = y2 - y0;
        double d = y1;
    
        return a *x * x * x + b * x * x + c * x + d;
    }
    
    double Interpolator::Linear2D(double a, double b, double c, double d, double x, double y) {
        double l1, l2;
        l1 = Linear(a, b, x);
        l2 = Linear(c, d, x);
        
        return Linear(l1, l2, y);
    }
    
    double Interpolator::Cosinus2D(double a, double b, double c, double d, double x, double y) {
        double l1, l2;
        l1 = Cosinus(a, b, x);
        l2 = Cosinus(c, d, x);
        
        return Cosinus(l1, l2, y);
    }
    
    double Interpolator::Cubic2D(double y0,  double y1, double y2,  double y3, double y10, double y11, double y12, double y13,
                   double y20, double y21, double y22, double y23, double y30, double y31, double y32, double y33,
                   double x,   double y) {
        
        double l1, l2, l3, l4;
        
        l1 = Cubic(y0, y1, y2, y3, x);
        l2 = Cubic(y10, y11, y12, y13, x);
        l3 = Cubic(y20, y21, y22, y23, x);
        l4 = Cubic(y30, y31, y32, y33, x);
        
        return Cubic(l1, l2, l3, l4, y);
    }
    
    double Interpolator::Linear3D(double a, double b, double c, double d, double e, double f, double g, double h, double x, double y, double z) {
        double l1, l2;
        
        l1 = Linear2D(a, b, c, d, x, y);
        l2 = Linear2D(e, f, g, h, x, y);
        
        return Linear(l1, l2, z);
    }
    
    double Interpolator::Cosinus3D(double a, double b, double c, double d, double e, double f, double g, double h, double x, double y, double z) {
        double l1, l2;
        
        l1 = Cosinus2D(a, b, c, d, x, y);
        l2 = Cosinus2D(e, f, g, h, x, y);
        
        return Cosinus(l1, l2, z);
    }

};