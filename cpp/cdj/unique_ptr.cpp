// Write your solution here
// C++20 for C++
// /////////////////////////////////////////////////////////////////////////
// If C++: Your code is automatically compiled with a precompiled header. //
// 99% of includes / packages are already added for you.                  //
// You do NOT need to add your own includes here.                         //
// /////////////////////////////////////////////////////////////////////////

namespace getcracked 
{
    template <typename T>
    struct custom_deleter
    {
        void operator()(T* pointer) const
        {
            delete pointer;
        }
    };

    template <typename T, typename custom_deleter = custom_deleter<T>>
    class unique_ptr
    {
    public:
        unique_ptr() : underlying_ptr(nullptr)
        { 
          
        }
        unique_ptr(T* pointer) : underlying_ptr(pointer)
        {
        }

        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete; 

        unique_ptr(unique_ptr&& other) noexcept
        {

        }

        unique_ptr& operator=(unique_ptr&& other) noexcept
        {

        }

        ~unique_ptr()
        {

        }

        T* release()
        {

        }

        void reset(T* pointer)
        {

        }

        bool is_owning() const { }


        T& operator*() const { }
        T* operator->() const { }
        operator bool() const { }

    private:
      T* underlying_ptr;
    
  };
}
