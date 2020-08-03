//
//  triangle.m
//  triangle(Serp)
//
//  Created by Тастеков Адиль Азатович on 11/03/15.
//  Copyright (c) 2015 Тастеков Адиль Азатович. All rights reserved.
//

#import "triangle.h"


@implementation triangle

void drawLine (float start_x, float start_y, float end_x, float end_y, float width) {
    NSBezierPath *line = [NSBezierPath bezierPath];
    [line moveToPoint:NSMakePoint(start_x, start_y)];
    [line lineToPoint:NSMakePoint(end_x, end_y)];
    [line setLineWidth: width];
    [[NSColor blackColor] set];
    [line stroke];
}

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

-(void) drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];

    NSPoint left = NSMakePoint(0, 0);
    NSPoint top = NSMakePoint(dirtyRect.size.width / 2, dirtyRect.size.width * sqrt(3) / 2);
    NSPoint right = NSMakePoint(dirtyRect.size.width, 0);
    drawTriangle(left, right, top, 1.0);
    rec(left, top, right, 5);
}

@end
