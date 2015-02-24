#include "Utils.h"

namespace utils
{
    void clearBuffer(std::istream& in)
    {
        in.clear();
        in.seekg(0, std::ios::end);

        if (in.fail())
            in.ignore(std::numeric_limits<std::streamsize>::max());

        else
            in.clear();
    }

    void readIStream(std::istream& in, unsigned int& value)
    {
        std::string tmp;
        in >> tmp;
        value = 0;

        if (in.eof() || in.bad())
        {
            std::cout << "Erreur interne !" << std::endl;

            if (!in.eof())
                clearBuffer(in);
        }
        else if (in.fail())
        {
            std::cout << "Saisie incorrect !" << std::endl;
            clearBuffer(in);
        }
        else
        {
            long long val = 0;

            std::istringstream stream(tmp);
            stream >> val;

            if (stream.fail() || !stream.eof())
            {
                std::cout << "Saisie incorrect !" << std::endl;
                value = 0;
            }
            else
            {
                value = static_cast<unsigned int>(std::abs(val));
            }
        }
    }

    void readIStream(std::istream& in, bool& value)
    {
        std::string tmp;
        in >> tmp;
        value = false;

        if (in.eof() || in.bad())
        {
            std::cout << "Erreur interne !" << std::endl;

            if (!in.eof())
                clearBuffer(in);
        }
        else if (in.fail())
        {
            std::cout << "Saisie incorrect !" << std::endl;
            clearBuffer(in);
        }
        else
        {
            bool val = 0;

            std::istringstream stream(tmp);
            stream >> val;

            if (stream.fail() || !stream.eof())
            {
                std::cout << "Saisie incorrect !" << std::endl;
                value = 0;
            }
            else
            {
                value = val;
            }
        }
    }
}