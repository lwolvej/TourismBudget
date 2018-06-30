//
// Created by 李杰 on 2018/6/29.
//

#ifndef TOURISMBUDGET_TOURISM_BUDGET_UTIL_H
#define TOURISMBUDGET_TOURISM_BUDGET_UTIL_H

#include <stdio.h>
#include <string.h>
#include "tourism_budget.h"

/**
 * 文件指正
 */
FILE *file;

/**
 * 写文件操作
 */
void file_write();

/**
 * 读文件操作
 */
void file_read();

/**
 * 关闭文件
 */
void file_close();

#endif
