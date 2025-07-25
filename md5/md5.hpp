/**
 * @file MD5.hpp
 * @author ИИ
 * @brief Заголовочный файл для MD5 класса, высчитывающий MD5 хэш.
 *
 * Этот файл определяет класс `MD5`, который предоставляет функции
 * для вычисления MD5-хешей строк и файлов. Класс также включает
 * статические методы для преобразования вычисленного хеша в строковое представление.
 *
 * @note Этот класс разработан как финальный класс и не может быть унаследован.
 */
#ifndef MD5_HPP
#define MD5_HPP

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

/**
 * @class MD5
 * @brief Класс для MD5-хеширования строк и файлов.
 *
 * Класс `MD5` предоставляет методы для вычисления хэшей MD5
 * для входных строк и файлов, а также для преобразования хэша
 * в шестнадцатеричное строковое представление. Этот класс инкапсулирует
 * внутреннюю логику вычисления MD5 и предоставляет статические методы
 * для простоты использования.
 *
 * @note Этот класс помечен как `final` и не может иметь подклассы.
 */
class MD5 final {
private:
    /**
     * @brief Размер input в байтах.
     */
    uint64_t size;

    /**
     * @brief Буфер для вычисления MD5
     */
    std::vector<uint32_t> buffer;

    /**
     * @brief Входные данные для процесса MD5 хэширования.
     */
    std::vector<uint8_t> input;

    /**
     * @brief Stores the resulting MD5 hash. ( Сохраняет полученный хеш MD5 )
     */
    std::vector<uint8_t> digest;

    /**
     * @brief Padding used during MD5 computation. ( Заполнение, используемое при вычислении MD5.)
     *
     * Статический массив, определяющий значения заполнения, необходимые
     * для выравнивания входных данных по границе 512 бит.
     */
    static uint8_t padding[64];

    /**
     * @brief Shift values used during MD5 computation. ( Значения сдвига, используемые при вычислении MD5.)
     *
     * Статический массив, определяющий величину сдвига для каждого
     * шага алгоритма MD5.
     */
    static uint32_t shift[64];

    /**
     * @brief Precomputed sine-derived constants. ( Предварительно вычисленные константы.)
     *
     * Статический массив констант, полученных из дробной части
     * значений sine, используемых в алгоритме MD5.
     */
    static uint32_t sineDerivation[64];

    /**
     * @brief Завершает вычисление MD5.
     *
     * Этот метод выполняет все необходимые окончательные
     * преобразования для завершения вычисления хеша MD5.
     */
    void finalize();

    /**
     * @brief Обрабатывает один 512-битный блок входных данных.
     *
     * @param inputVec  Вектор, содержащий входные данные для обработки.
     */
    void step(const std::vector<uint32_t>& inputVec);

    /**
     * @brief Обновляет внутреннее состояние с помощью входных данных.
     *
     * @param inputBuffer Указатель на буфер входных данных.
     * @param inputLength Длина входных данных в байтах.
     */
    void update(
        const uint8_t* inputBuffer,
        size_t inputLength
    );

protected:
    /**
     * @brief Создает объект `MD5`.
     *
     * Конструктор защищён от прямого создания экземпляров.
     * Пользователям следует полагаться на статические методы, предоставляемые классом.
     */
    MD5();

public:
    /**
     * @brief Вычисляет MD5-хеш строки.
     *
     * @param input Входная строка для хэширования.
     * @return Вектор байтов, представляющий хеш MD5.
     */
    static std::vector<uint8_t> digestString(const std::string& input);

    /**
     * @brief Вычисляет MD5-хеш файла.
     *
     * @param filepath Путь к файлу для хэширования.
     * @return Вектор байтов, представляющий хеш MD5.
     */
    static std::vector<uint8_t> digestFile(const std::string& filepath);

    /**
     * @brief Вычисляет MD5-хеш строки и возвращает его в виде шестнадцатеричной строки.
     *
     * @param input Входная строка для хэширования.
     * @return Строка, представляющая хеш MD5 в шестнадцатеричном формате.
     */
    static std::string toHash(const std::string& input);

    /**
     * @brief Вычисляет MD5-хеш файла и возвращает его в виде шестнадцатеричной строки.
     *
     * @param filepath Путь к файлу для хэширования.
     * @return Строка, представляющая хеш MD5 в шестнадцатеричном формате.
     */
    static std::string fileToHash(const std::string& filepath);
};

#endif
