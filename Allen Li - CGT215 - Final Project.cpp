// Allen Li - CGT215 - Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;
using namespace std;

void printMenu() {
    cout << "Please Select which operation to perform:" << endl;
    cout << "1. Red Image" << endl;
    cout << "2. Green Image" << endl;
    cout << "3. Blue Image" << endl;
    cout << "4. Gray Scale" << endl;
    cout << "5. Blur Effect" << endl;
    cout << "6. Sharpen Effect" << endl;
    cout << "7. Exit" << endl;
    cout << "Your Selection: ";
}

void Red(Image input, Image output, int width, int height) {
    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1; x++) {
            Color c = input.getPixel(x, y);
            Color rC(c.r, 0, 0);
            output.setPixel(x, y, rC);
        }
    }

    RenderWindow window(VideoMode(width, height), "Here's the output");
    Sprite sprite1;
    Texture tex1;
    tex1.loadFromImage(output);
    sprite1.setTexture(tex1);
    window.clear();
    window.draw(sprite1);
    window.display();
    while (true);
}

void Green(Image input, Image output, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color c = input.getPixel(x, y);
            Color gC(0, c.g, 0);
            output.setPixel(x, y, gC);
        }
    }

    RenderWindow window(VideoMode(width, height), "Here's the output");
    Sprite sprite1;
    Texture tex1;
    tex1.loadFromImage(output);
    sprite1.setTexture(tex1);
    window.clear();
    window.draw(sprite1);
    window.display();
    while (true);
}

void Blue(Image input, Image output, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color c = input.getPixel(x, y);
            Color bC(0, 0, c.b);
            output.setPixel(x, y, bC);
        }
    }

    RenderWindow window(VideoMode(width, height), "Here's the output");
    Sprite sprite1;
    Texture tex1;
    tex1.loadFromImage(output);
    sprite1.setTexture(tex1);
    window.clear();
    window.draw(sprite1);
    window.display();
    while (true);
}

void Gray(Image input, Image output, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color c = input.getPixel(x, y);
            int average = (c.r + c.g + c.b) / 3;
            Color grayScale(average, average, average);
            output.setPixel(x, y, grayScale);
        }
    }

    RenderWindow window(VideoMode(width, height), "Here's the output");
    Sprite sprite1;
    Texture tex1;
    tex1.loadFromImage(output);
    sprite1.setTexture(tex1);
    window.clear();
    window.draw(sprite1);
    window.display();
    while (true);
}

void Blur(Image input, Image output, int width, int height) {
    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1; x++) {
            int minX = max(x - 1, 0);
            int maxX = min(x + 1, width - 1);
            int minY = max(y - 1, 0);
            int maxY = min(y + 1, height - 1);
            int pixCount = 0;
            int rCount = 0;
            int bCount = 0;
            int gCount = 0;
            for (int pixY = minY; pixY <= maxY; pixY++) {
                for (int pixX = minX; pixX <= maxX; pixX++) {
                    pixCount++;
                    Color pixC = input.getPixel(pixX, pixY);
                    rCount += pixC.r;
                    gCount += pixC.g;
                    bCount += pixC.b;
                }
            }
            Color blurC = Color(rCount / pixCount, gCount / pixCount, bCount / pixCount);
            output.setPixel(x, y, blurC);
        }
    }
    Texture tex1;
    tex1.loadFromImage(output);
    RenderWindow window(VideoMode(width, height), "Here's the output");
    Sprite sprite1;
    sprite1.setTexture(tex1);
    window.draw(sprite1);
    window.display();

    while (true);
}

void Sharpen(Image input, Image output, int width, int height) {
    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1; x++) {
            int minX = max(x - 1, 0);
            int maxX = min(x + 1, width - 1);
            int minY = max(y - 1, 0);
            int maxY = min(y + 1, height - 1);
            int pixCount = 0;
            int rCount = 0;
            int bCount = 0;
            int gCount = 0;
            for (int pixY = minY; pixY <= maxY; pixY++) {
                for (int pixX = minX; pixX <= maxX; pixX++) {
                    Color pixC = input.getPixel(pixX, pixY);
                    if ((pixY != y) && (pixX != x)) {
                        pixCount++;
                        rCount += pixC.r * 0;
                        gCount += pixC.g * 0;
                        bCount += pixC.b * 0;
                    }
                    else if ((pixY == y) && (pixX == x)) {
                        pixCount++;
                        rCount += pixC.r * 5;
                        gCount += pixC.g * 5;
                        bCount += pixC.b * 5;
                    }
                    else {
                        pixCount++;
                        rCount += pixC.r * -1;
                        gCount += pixC.g * -1;
                        bCount += pixC.b * -1;
                    }
                }
            }
            if (rCount > 255) {
                rCount = 255;
            }
            else if (rCount < 0) {
                rCount = 0;
            }
            if (gCount > 255) {
                gCount = 255;
            }
            else if (gCount < 0) {
                gCount = 0;
            }
            if (bCount > 255) {
                bCount = 255;
            }
            else if (bCount < 0) {
                bCount = 0;
            }
            Color sharpC = Color(rCount, gCount, bCount);
            output.setPixel(x, y, sharpC);
        }
    }
    Texture tex1;
    tex1.loadFromImage(output);
    RenderWindow window(VideoMode(width, height), "Here's the output");
    Sprite sprite1;
    sprite1.setTexture(tex1);
    window.draw(sprite1);
    window.display();

    while (true);
}

int main() {
    int choice;
    Image img;
    img.loadFromFile("images1/cat.png");
    int width = img.getSize().x;
    int height = img.getSize().y;
    Image outImg;
    outImg.create(width, height);

    do {
        printMenu();
        std::cin >> choice;
        if (choice > 6 || choice < 1) {
            return 0;
        }
        else if (choice == 1) {
            Red(img, outImg, width, height);
        }
        else if (choice == 2) {
            Green(img, outImg, width, height);
        }
        else if (choice == 3) {
            Blue(img, outImg, width, height);
        }
        else if (choice == 4) {
            Gray(img, outImg, width, height);
        }
        else if (choice == 5) {
            Blur(img, outImg, width, height);
        }
        else if (choice == 6) {
            Sharpen(img, outImg, width, height);
        }
        
    } while (true);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
