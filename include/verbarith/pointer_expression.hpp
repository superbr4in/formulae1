#pragma once

#include <verbarith/expression.hpp>

namespace vra
{
    template <expression_typename T>
    class pointer_expression : public expression<std::uintptr_t>
    {
        using expression::expression;

    public:

        [[nodiscard]] expression<T> dereference() const noexcept;
    };
}

namespace std
{
    template <vra::expression_typename T>
    struct hash<vra::pointer_expression<T>>
    {
        [[nodiscard]] std::size_t operator()(vra::pointer_expression<T> const&) const noexcept;
    };
}
