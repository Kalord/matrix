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
    Matrix(size_t rows, size_t columns, T** matrix) :
    rows(rows), columns(columns) 
    {
        this->matrix = matrix;
    }

    /**
     * Деструктор
     **/
    ~Matrix()
    {
        for(int i = 0; i < rows; i++) delete [] this->matrix[i];
        delete [] this->matrix;
    }

    size_t getSizeRows()
    {
        return this->rows;
    }

    size_t getSizeColumns()
    {
        return this->columns;
    }

    T* operator[](int i)
    {
        return this->matrix[i];
    }

    T get(size_t row, size_t column)
    {
        return this->matrix[row][column];
    }

    /**
     * Сложение матрицы на матрицу
     **/
    /*
    Matrix<T>& operator+(const Matrix<T>& m)
    {
        //Матрицы должны быть одинакового размера
        if(this->getSizeRows() != m->getSizeRows() ||
           this->getSizeColumns() != m->getSizeColumns()
        ) return nullptr;

        std::vector<std::vector<T>> accumulator;
        for(int i = 0; i < this->getSizeRows(); i++)
        {
            accumulator.push_back(std::vector<T>{});
            for(int j = 0; j < this->getSizeColumns(); j++)
            {
                accumulator.push_back(this[i][j] + m[i][j]);
            }
        }

        Matrix<T> result(accumulator);
        return result;
    }
    */
};