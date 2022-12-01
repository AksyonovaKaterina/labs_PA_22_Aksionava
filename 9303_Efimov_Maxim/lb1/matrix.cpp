#include "matrix.h"

Matrix::Matrix(){}

Matrix::Matrix(int N, int M)
{
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<> distrib(0, 9);

    matrix = std::vector<std::vector<int>> (N);
    for (auto &vec : matrix) {
        vec.reserve(M);
        for (int i = 0;i < M;i++) {
            vec.push_back(distrib(generator));
        }
    }
}

void Matrix::add(Matrix& term)
{
    for(auto row = 0; row < matrix.size(); row++) {
        for(auto column = 0; column < matrix[row].size(); column++) {
            matrix[row][column] += term.matrix[row][column];
        }
    }
}

int * Matrix::serialization()
{
    auto count = matrix.size() * matrix[0].size();
    int *buf = new int[count];
    int index = 0;
    for(auto row = 0; row < matrix.size(); row++) {
        for(auto column = 0; column < matrix[row].size(); column++) {
            buf[index] = matrix[row][column];
            index++;
            }
        }
    return buf;
}

void Matrix::deserialization(int* buf,int N, int M)
{
    matrix = std::vector<std::vector<int>> (N);
    for (auto &vec : matrix) {
        vec.resize(M);
    }
    int index = 0;
    for(auto row = 0; row < matrix.size(); row++) {
        for(auto column = 0; column < matrix[row].size(); column++) {
            matrix[row][column] = buf[index];
            index++;
        }
    }
}

void Matrix::fileOutput(char* fileName)
{
        std::ofstream fout(fileName);
        for(auto row = 0; row < matrix.size(); row++) {
            for(auto column = 0; column < matrix[row].size(); column++) {
                fout << matrix[row][column] << " ";
                }
            fout << std::endl;
            }
        fout.close();
}
