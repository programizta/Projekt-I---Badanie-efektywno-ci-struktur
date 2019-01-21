#pragma once

struct TreeNode
{
    int value; // deklaracja wartości węzła drzewa binarnego
    TreeNode *up;
    TreeNode *left;
    TreeNode *right; // deklaracja wskaźników na sąsiadujące węzły w drzewie poszukiwań binarnych

    TreeNode(); // konstruktor pojedynczego węzła
    ~TreeNode(); // destruktor węzła
};
