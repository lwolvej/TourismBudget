//
// Created by 李杰 on 2018/6/29.
//

#ifndef TOURISMBUDGET_MAIN_H
#define TOURISMBUDGET_MAIN_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM  0xFFFFFFFF

//最终的结果
double MIN_BUDGET;

//距离
double distance;
//车油箱容量
double capacity;
// 初始费用
double cost;
//消耗
double consume;
// 站点数量
int num;

//每个加油站：距离和油价
typedef struct Station {
    double length;
    double price;
} *Station;

//生成所有站点
Station stations[51];

//记录路径
int vis[51];

/**
 *深搜操作
 * @param past 上一次加油的站点
 * @param now 当前的站点
 * @param money 花费的钱
 * @param current_tank 当前的油量
 */
void dfs(int past, int now, double money, double current_tank, int book[]);

/**
 * 判断当前站点的加油策略
 * @param now 当前的站点
 * @param current_tank 当前的油量
 * @return 1:必须加油;2.不需要加油;3.可以加可以不加
 */
int way_judge(int now, double current_tank);

/**
 * 初始化
 */
void init();

/**
 * 开始执行
 */
void start();

/**
 * 销毁操作
 */
void destroy();

#endif
