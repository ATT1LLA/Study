//
//  fract.m
//  Fractals
//
//  Created by Тастеков Адиль Азатович on 24/09/15.
//  Copyright (c) 2015 Тастеков Адиль Азатович. All rights reserved.
//

#import "fract.h"

#include <math.h>

@implementation fract

int n = 2, max = 15;

void drawLine (float start_x, float start_y, float end_x, float end_y, float width) {
    NSBezierPath *line = [NSBezierPath bezierPath];
    [line moveToPoint:NSMakePoint(start_x, start_y)];
    [line lineToPoint:NSMakePoint(end_x, end_y)];
    [line setLineWidth: width];
    [[NSColor blackColor] set];
    [line stroke];
}
void drawLine_withHole (NSPoint start, NSPoint end) {
    float len_x = (end.x - start.x) / 3;
    float len_y = (end.y - start.y) / 3;
    
    NSPoint new_start = NSMakePoint(start.x + len_x, start.y + len_y);
    NSPoint new_end = NSMakePoint(start.x + 2 * len_x, start.y + 2 * len_y);
    
    drawLine(start.x, start.y, new_start.x, new_start.y, 2);
    drawLine(new_end.x, new_end.y, end.x, end.y, 2);
}

//Треугольник Серпинского
void drawTriangle(NSPoint left, NSPoint right, NSPoint top, float width) {
    drawLine(left.x, left.y, top.x, top.y, width);
    drawLine(top.x, top.y, right.x, right.y, width);
    drawLine(right.x, right.y, left.x, left.y, width);
}
void rec(NSPoint left, NSPoint right, NSPoint top, int counter) {
    NSPoint mid_l_t, mid_t_r, mid_l_r;
    mid_l_t.x = (left.x + top.x) / 2;
    mid_l_t.y = (left.y + top.y) / 2;
    mid_t_r.x = (top.x + right.x) / 2;
    mid_t_r.y = (top.y + right.y) / 2;
    mid_l_r.x = (left.x + right.x) / 2;
    mid_l_r.y = (left.y + right.y) / 2;
    drawTriangle(mid_l_t, mid_t_r, mid_l_r, 1.0);
    if (counter) {
        rec(mid_l_r, left, mid_l_t, counter - 1);
        rec(mid_l_t, top, mid_t_r, counter - 1);
        rec(mid_t_r, right, mid_l_r, counter - 1);
    }
}

//Квадрат Серпинского
void drawRect_1 (NSPoint left_down, NSPoint right_down, NSPoint left_top, NSPoint right_top, float width) {
    drawLine(left_down.x, left_down.y, left_top.x, left_top.y, width);
    drawLine(left_top.x, left_top.y, right_top.x, right_top.y, width);
    drawLine(right_down.x, right_top.y, right_down.x, right_down.y, width);
    drawLine(right_down.x, right_down.y, left_down.x, left_down.y, width);
}
void rec_Rect(NSPoint left_down, NSPoint right_down, NSPoint left_top, NSPoint right_top, int counter) {
    if (counter == n) {}
    else {
    NSPoint top_1 = NSMakePoint((right_top.x - left_top.x) / 3 + left_top.x, right_top.y);
    NSPoint top_2 = NSMakePoint(2 * (right_top.x - left_top.x) / 3 + left_top.x, top_1.y);
    NSPoint left_1 = NSMakePoint(left_down.x, (left_top.y - left_down.y) / 3 + left_down.y);
    NSPoint left_2 = NSMakePoint(left_1.x, 2 * (left_top.y - left_down.y) / 3 + left_down.y);
    NSPoint down_1 = NSMakePoint((right_down.x - left_down.x) / 3 + left_down.x, right_down.y);
    NSPoint down_2 = NSMakePoint(2 * (right_down.x - left_down.x) / 3 + left_down.x, down_1.y);
    NSPoint right_1 = NSMakePoint(right_top.x, (right_top.y - right_down.y) / 3 + right_down.y);
    NSPoint right_2 = NSMakePoint(right_1.x, 2 * (right_top.y - right_down.y) / 3 + right_down.y);
    
    NSPoint left_top_1 = NSMakePoint(top_1.x, left_2.y);
    NSPoint left_down_1 = NSMakePoint(top_1.x, left_1.y);
    NSPoint right_down_1 = NSMakePoint(top_2.x, left_1.y);
    NSPoint right_top_1 = NSMakePoint(top_2.x, left_2.y);
    
    drawLine(top_1.x, top_1.y, down_1.x, down_1.y, 2);
    drawLine(top_2.x, top_2.y, down_2.x, down_2.y, 2);
    drawLine(left_1.x, left_1.y, right_1.x, right_1.y, 2);
    drawLine(left_2.x, left_2.y, right_2.x, right_2.y, 2);
    
    rec_Rect(left_down, down_1, left_1, left_down_1, counter + 1);
    rec_Rect(down_1, down_2, left_down_1, right_down_1, counter + 1);
    rec_Rect(down_2, right_down, right_down_1, right_1, counter + 1);
    rec_Rect(right_down_1, right_1, right_top_1, right_2, counter + 1);
    rec_Rect(right_top_1, right_2, top_2, right_top, counter + 1);
    rec_Rect(left_top_1, right_top_1, top_1, top_2, counter + 1);
    rec_Rect(left_2, left_top_1, left_top, top_1, counter + 1);
    rec_Rect(left_1, left_down_1, left_2, left_top_1, counter + 1);
        
    }

}

//Прямая Кохха
void drawLine1 (NSPoint start, NSPoint end, float width) {
    NSBezierPath *line = [NSBezierPath bezierPath];
    [line moveToPoint:NSMakePoint(start.x, start.y)];
    [line lineToPoint:NSMakePoint(end.x, end.y)];
    [line setLineWidth: width];
    [[NSColor blackColor] set];
    [line stroke];
}

void drawKochLine_rec (NSPoint start, NSPoint center, NSPoint end, int count) {
    NSPoint newStart = NSMakePoint(start.x + (end.x - start.x) / 3, start.y + (end.y - start.y) / 3);
    NSPoint newEnd = NSMakePoint(start.x + (end.x - start.x) * 2 / 3, start.y + (end.y - start.y) * 2 / 3);
    NSPoint new_center_left1 = NSMakePoint(start.x + (center.x - start.x) / 3, start.y + (center.y - start.y) / 3);
    NSPoint new_center_left2 = NSMakePoint(start.x + (center.x - start.x) * 2 / 3, start.y + (center.y - start.y) * 2 / 3);
    NSPoint new_center_right1 = NSMakePoint(center.x + (end.x - center.x) * 1 / 3, center.y + (end.y - center.y) * 1 / 3);
    NSPoint new_center_right2 = NSMakePoint(center.x + (end.x - center.x) * 2 / 3, center.y + (end.y - center.y) * 2 / 3);
    
    if (count == n) {
        drawLine1(start, newStart, 3);
        drawLine1(newStart, center, 3);
        drawLine1(center, newEnd, 3);
        drawLine1(newEnd, end, 3);
    } else {
        drawKochLine_rec(start, new_center_left1, newStart, count + 1);
        drawKochLine_rec(newStart, new_center_left2, center, count + 1);
        drawKochLine_rec(center, new_center_right1, newEnd, count + 1);
        drawKochLine_rec(newEnd, new_center_right2, end, count + 1);
    }
}

void drawKochLine (NSPoint start, NSPoint end) {
    NSPoint center = NSMakePoint((start.x + end.x) / 2, start.y + (end.x - start.x) / 3 * sqrt(3) / 2);
    
    drawKochLine_rec(start, center, end, 0);
}

// Снежинка Коха
void drawKochTriangle_rec (NSPoint left, NSPoint top, NSPoint right, int count) {
    if (count == n) {}
    else {
        NSPoint center_left_top = NSMakePoint(left.x, left.y + (top.y - left.y) * 2 / 3);
        NSPoint center_top_right = NSMakePoint(right.x, top.y + (right.y - top.y) / 3);
        NSPoint center_right_left = NSMakePoint(top.x, right.y - (right.x - left.x) / 3 * sqrt(3) / 2);
    
        drawKochLine_rec(left, center_left_top, top, count + 1);
        drawKochLine_rec(top, center_top_right, right, count + 1);
        drawKochLine_rec(right, center_right_left, left, count + 1);
    }
}

void drawSnejinkyKocha(NSPoint left, NSPoint top, NSPoint right) {
    drawKochTriangle_rec(left, top, right, 0);
}

//Дерево
void derevo_rec (double x, double y, double l, double alpha) {
    if (l > max) {
        l *= 0.7;
        
        drawLine(x, y, (int)(x + l * cos(alpha)), (int)(y + l * sin(alpha)), 3);
        
        x = x + l * cos(alpha);
        y = y + l * sin(alpha);
        
        derevo_rec(x , y, l, alpha + (3.14 / 4));
        derevo_rec(x, y, l, alpha - (3.14 / 4));
        
    }
}

void derevo (NSPoint start, double l) {
    derevo_rec(start.x, start.y, l, 3.14 / 2);
}

-(void) drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    //Треугольник Серпинского
    /*NSPoint left = NSMakePoint(0, 0);
    NSPoint top = NSMakePoint(dirtyRect.size.width / 2, dirtyRect.size.height);
    NSPoint right = NSMakePoint(dirtyRect.size.width, 0);
    drawTriangle(left, right, top, 1.0);
    rec(left, top, right, 10);*/ //треугольник серпинского

    // Ковер Серпинского
    /*NSPoint left_down = NSMakePoint(0, 0);
    NSPoint right_down = NSMakePoint(dirtyRect.size.width, 0);
    NSPoint left_top = NSMakePoint(0, dirtyRect.size.height);
    NSPoint right_top = NSMakePoint(dirtyRect.size.width, dirtyRect.size.height);
    drawRect_1(left_down, right_down, left_top, right_top, 5);
    rec_Rect(left_down, right_down, left_top, right_top, 0);*/
    
    //Прямая Кохха
    /*NSPoint start = NSMakePoint(0, dirtyRect.size.height / 2);
    NSPoint end = NSMakePoint(dirtyRect.size.width, dirtyRect.size.height / 2);
    drawKochLine(start, end);*/
    
    //Снежинка Кохха
    /*NSPoint left = NSMakePoint(dirtyRect.size.width * (1 - sqrt(3) / 2) / 2, dirtyRect.size.height / 4);
    NSPoint top = NSMakePoint(dirtyRect.size.width / 2, dirtyRect.size.height);
    NSPoint right = NSMakePoint(dirtyRect.size.width - left.x,  dirtyRect.size.height / 4);
    drawSnejinkyKocha(left, top, right);*/
    
    // Derevo
    NSPoint start = NSMakePoint(dirtyRect.size.width / 2, 0);
    
    derevo(start, dirtyRect.size.height / 2);
    
    
}

@end
