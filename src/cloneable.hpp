#ifndef IAD_2A_CLONEABLE_HPP
#define IAD_2A_CLONEABLE_HPP
///////////////////////////////////////////////////////////////////// | Includes
#include <memory>

//////////////////////////////////////////////////// | Namespace: NeuralNetworks
namespace NeuralNetworks
{
    /////////////////////////////////////////////////// | Interface: Cloneable <
    template <typename T>
    class Cloneable
    {
    protected:
        //======================================================= | Behaviour <<
        //--------------------------------------------------- | Constructors <<<
        Cloneable
                () = default;

        Cloneable
                (Cloneable const &) = default;

        Cloneable
                (Cloneable &&) noexcept = default;

        //------------------------------------------------------ | Operators <<<
        Cloneable &operator=
                (Cloneable const &) = default;

        Cloneable &operator=
                (Cloneable &&) noexcept = default;

        //----------------------------------------------------- | Destructor <<<
        virtual ~Cloneable
                () noexcept = 0;

    private:
        //======================================================= | Behaviour <<
        //----------------------------------------------------------- | Main <<<
        virtual std::unique_ptr<T> clone
                () const = 0;

        virtual operator std::unique_ptr<T>
                () const = 0;
    };

    //=========================================================== | Behaviour <<
    //--------------------------------------------------------- | Destructor <<<
    template <typename T>
    inline Cloneable<T>::~Cloneable
            () noexcept = default;
}

////////////////////////////////////////////////////////////////////////////////
#endif // IAD_2A_CLONEABLE_HPP
