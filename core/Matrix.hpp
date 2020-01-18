#pragma once

#include <sys/types.h>
#include <iostream>

/**
 * Класс для работы с матрицами
 * 
 * Данный класс реализует свойства матрицы и имеет следующие операции:
 *      1)Сложение с другой матрицей
 *      2)Умножение на число
 *      3)Умножение на другую матрицу
 * 
 * @author Artem Tyutnev <artem.tyutnev.developer@gmail.com>
 **/
template<typename T>
class Matrix
{
private:
    /**
     * Матрица, представленная двумерным массивом
     **/
    T** matrix;
    /**
     * Количество строк в матрице
     **/
    size_t rows;
    /**
     * Количество колонок в матрице
     **/
    size_t columns;
public:
    /**
     * Конструктор
     **/
    Matrix(size_t rows, size_t columns, T** matrix = nullptr) :
    rows(rows), columns(columns), matrix(matrix)
    {}

    /**
     * Деструктор
     **/
    ~Matrix()
    {
        for(int i = 0; i < this->getSizeRows(); i++) delete [] this->matrix[i];
        delete [] this->matrix;
    }

    /**
     * Инициализация матрицы
     **/
    void initMatrix(size_t defaultValue = 0)
    {
        this->matrix = new T*[this->getSizeRows()];

        for(int i = 0; i < this->getSizeRows(); i++)
        {
            this->matrix[i] = new T[this->getSizeColumns()];
            for(int j = 0; j < this->getSizeColumns(); j++) this->matrix[i][j] = defaultValue;
        }
    }

    size_t getSizeRows()
    {
        return this->rows;
    }

    size_t getSizeColumns()
    {
        return this->columns;
    }

    T* operator[](size_t i)
    {
        return this->matrix[i];
    }

    T get(size_t row, size_t column)
    {
        return this->matrix[row][column];
    }

    void set(size_t row, size_t column, T value)
    {
        this->matrix[row][column] = value;
    }

    /**
     * Проверка равности матриц
     * Матрицы считаются равными, когда:
     *      1)Имеют одинаковый размер
     *      2)Элемент первой матрице равен элементу второй матрице,
     *      то есть A[i][j] == B[i][j]
     **/
    bool operator==(Matrix<T>& m)
    {
        if(this->getSizeRows() != m.getSizeRows() || 
           this->getSizeColumns() != m.getSizeColumns()
        ) return false;

        for(int i = 0; i < this->getSizeRows(); i++)
        {
            for(int j = 0; j < this->getSizeColumns(); j++)
            {
                if(this->get(i, j) != m[i][j]) return false;
            }
        }

        return true;
    }

    /**
     * Сложение матрицы на матрицу
     * Складывать можно только матрицы одинакового размера
     **/
    Matrix<T> operator+(Matrix<T>& m)
    {
        Matrix<T> accumulator(
            this->getSizeRows(),
            this->getSizeColumns()
        );
        accumulator.initMatrix();

        for(int i = 0; i < this->getSizeRows(); i++)
        {
            for(int j = 0; j < this->getSizeColumns(); j++)
            {
                accumulator.set(i, j, this->get(i, j) + m.get(i, j));
            }
        }

        return accumulator;
    }

    /**
     * Умножение на скаляр
     **/
    Matrix<T> operator*(T scalar)
    {
        Matrix<T> accumulator(
            this->getSizeRows(),
            this->getSizeColumns()
        );
        accumulator.initMatrix();

        for(int i = 0; i < this->getSizeRows(); i++)
        {
            for(int j = 0; j < this->getSizeColumns(); j++)
            {
                accumulator.set(i, j, this->get(i, j) * scalar);
            }
        }

        return accumulator;
    }

    
};