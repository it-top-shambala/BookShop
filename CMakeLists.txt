cmake_minimum_required(VERSION 3.22)
project(Creational_design_patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(BookShop main.cpp "Product.h" "Sale.h" "Purchase.h" "Wholesale.h" "Accountant.h" "Retail.h" )
