cmake_minimum_required(VERSION 3.10)
project(TourismBudget C)

set(CMAKE_C_STANDARD 99)

add_executable(
        TourismBudget
        tourism_budget.c
        tourism_budget.h
        test.c tourism_budget_util.c
        tourism_budget_util.h)