cmake_minimum_required(VERSION 3.22)
project(Creational_design_patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(BookShop main.cpp "Items/Item.h" "Items/Item_Book.h" "Items/Item_Pen.h" "Shop.h" "Base/Base.h" "Base/Base_Sold.h")
