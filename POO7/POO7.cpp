
#if 0
class Cualquiera
{
public:
    Cualquiera()
    {
        // código para hacer A
    }

    Cualquiera(int valor)
    {
        // código para hacer A
        // código para hacer B
    }
};





class Cualquiera
{
public:
    Cualquiera()
    {
        // Código para hacer A
    }

    Cualquiera(int valor)
    {
        Cualquiera(); // Usar el otro constructor para hacer A no funciona
        // código para hacer B
    }
};







class Cualquiera
{
private:

public:
    Cualquiera()
    {
        // Código para hacer A
    }

    Cualquiera(int valor) : Cualquiera{} // usamos el constructor predeterminado Cualquiera() para hacer A
    {
        // código para hacer B
    }

};







#include <string>
#include <iostream>

class Alumno
{
private:
    int m_id{};
    std::string m_nombre{};

public:
    Alumno(int id = 0, const std::string& nombre = "") :
        m_id{ id }, m_nombre{ nombre }
    {
        std::cout << "Alumno " << m_nombre << " creado.\n";
    }

    // Usar un constructor delegado para minimizar código redundante
    Alumno(const std::string& nombre) : Alumno{ 0, nombre }
    { }
};





class Cualquiera
{
private:
    const int m_valor{ 0 };

public:
    Cualquiera()
    {
        // Código para hacer alguna tarea común como abrir un archivo
    }

    Cualquiera(int valor) : m_valor{ valor } // debemos inicializar m_valor porque es const
    {
        //¿Cómo obtenemos el código de la inicialización común en Cualquiera()?
    }

};





#include <iostream>

class Cualquiera
{
private:
    const int m_valor{ 0 };

    void setup() // setup es private así que solo puede ser usada por nuestros constructors
    {
        // Código para hacer alguna tarea común como abrir un archivo
        std::cout << "Configuración inicial...\n";
    }

public:
    Cualquiera()
    {
        setup();
    }

    Cualquiera(int valor) : m_valor{ valor } // debemos inicializar m_valor porque es const
    {
        setup();
    }

};

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    Cualquiera a;
    Cualquiera b{ 5 };

    return 0;
}








#include <iostream>
class Cualquiera
{
private:
    int m_a{ 1 };
    int m_b{ 2 };

public:
    Cualquiera()
    {
    }

    Cualquiera(int a, int b)
        : m_a{ a }, m_b{ b }
    {
    }

    void imprimir()
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset()
    {
        m_a = 1;
        m_b = 2;
    }
};

int main()
{
    Cualquiera a{ 3, 4 };
	
    a.imprimir();
    a.reset();
    a.imprimir();

    return 0;
}

#endif






#include <iostream>

class Cualquiera
{
private:
    int m_a{ 5 };
    int m_b{ 6 };


public:
    Cualquiera()
    {
    }

    Cualquiera(int a, int b)
        : m_a{ a }, m_b{ b }
    {
    }

    void imprimir()
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset()
    {
        *this = Cualquiera{ }; // crea nuevo objeto Cualquiera, luego usa asignación para sobrescribir nuestro objeto implícito
    }
};

int main()
{
    Cualquiera a{ 1, 2 };
	
    a.imprimir();
    a.reset();
    a.imprimir();

    return 0;
}




#if 0

#endif


