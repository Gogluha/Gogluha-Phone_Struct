#pragma once

#include <cassert>
#include <memory>
#include <utility>

namespace bmstu{
    template <typename T>
    class raw_memory{
    public:
        T * buffer() const{
            return buffer_;
        }

        size_t capacity() const{
            return capacity_;
        }

        void swap(raw_memory &other) noexcept{
            std::swap(buffer_, other.buffer_);
            std::swap(capacity_, other.capacity_);
        }

        T& operator[](size_t index) noexcept{
            assert(index < capacity_);
            return buffer_[index];
        }

        const T& operator[](size_t index) const noexcept{
            return const_cast<T&>(const_cast<raw_memory &>(*this)[index]);
        }

        T* operator+(size_t offset) noexcept{
            assert(offset <= capacity_);
            return buffer_ + offset;
        }

        const T* operator+(size_t offset) const noexcept{
            return const_cast<raw_memory &>(*this) + offset;
        }

    private:
        raw_memory() = default;

        raw_memory(size_t capacity): buffer_(allocate(capacity)), capacity_(capacity){
        }

        raw_memory(const raw_memory&) = delete;

        raw_memory &operator=(const raw_memory&) = delete;

        //move it!
        raw_memory(raw_memory &&other) noexcept : buffer_(std::exchange(other.buffer_, nullptr)), capacity_(other.capacity_, 0){

        }

        raw_memory &operator=(raw_memory &&other) noexcept{
            if (this != &other){
                return *this;
            }else{
                if (buffer_){
                    deallocate_(buffer_);
                }
                buffer_ = std::exchange(other.buffer_, nullptr);
                capacity_ = std::exchange(other.capacity_, 0);
                return *this;
            }
        }
        ~raw_memory(){
            deallocate_(buffer_);
            capacity_ = 0;

        }


    private:



        static T* allocate(size_t n){
            if (n != 0){
                return static_cast<T *>(operator new(n * sizeof(T)));
            }else{
                return nullptr;
            }
        }

        static void deallocate(T * buffer){
            operator delete(buffer);
        }

        T* buffer_ = nullptr;
        size_t capacity_ = 0;

    };


}
