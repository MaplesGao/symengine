#ifndef SYMENGINE_MATRIXEXPR_H
#define SYMENGINE_MATRIXEXPR_H

#include <symengine/basic.h>
#include <symengine/integer.h>

namespace SymEngine
{

class MatrixExpr : public Basic
{
};

class IdentityMatrix : public MatrixExpr
{
private:
    RCP<const Basic> n_; // n >= 0

public:
    IdentityMatrix(const RCP<const Basic> &n) : n_(n)
    {
        SYMENGINE_ASSIGN_TYPEID();
        SYMENGINE_ASSERT(is_canonical(n));
    }

    IMPLEMENT_TYPEID(SYMENGINE_IDENTITYMATRIX)
    hash_t __hash__() const override;
    bool __eq__(const Basic &o) const override;
    int compare(const Basic &o) const override;
    vec_basic get_args() const override;
    bool is_canonical(const RCP<const Basic> &n) const;

    inline const RCP<const Basic> &size() const
    {
        return n_;
    }
};

RCP<const MatrixExpr> identity_matrix(const RCP<const Basic> &n);

class ZeroMatrix : public MatrixExpr
{
private:
    RCP<const Basic> m_, n_; // m >= 0, n >= 0

public:
    ZeroMatrix(const RCP<const Basic> &m, const RCP<const Basic> &n)
        : m_(m), n_(n)
    {
        SYMENGINE_ASSIGN_TYPEID();
    }

    IMPLEMENT_TYPEID(SYMENGINE_ZEROMATRIX)
    hash_t __hash__() const override;
    bool __eq__(const Basic &o) const override;
    int compare(const Basic &o) const override;
    vec_basic get_args() const override;
    bool is_canonical(const RCP<const Basic> &m,
                      const RCP<const Basic> &n) const;

    inline const RCP<const Basic> &nrows() const
    {
        return m_;
    }

    inline const RCP<const Basic> &ncols() const
    {
        return n_;
    }
};

RCP<const MatrixExpr> zero_matrix(const RCP<const Basic> &m,
                                  const RCP<const Basic> &n);

class DiagonalMatrix : public MatrixExpr
{
private:
    vec_basic diag_;

public:
    DiagonalMatrix(const vec_basic &container) : diag_(container)
    {
        SYMENGINE_ASSIGN_TYPEID();
        SYMENGINE_ASSERT(is_canonical(container));
    }

    IMPLEMENT_TYPEID(SYMENGINE_DIAGONALMATRIX)
    hash_t __hash__() const override;
    bool __eq__(const Basic &o) const override;
    int compare(const Basic &o) const override;
    bool is_canonical(const vec_basic &container) const;

    vec_basic get_args() const override
    {
        return vec_basic(diag_.begin(), diag_.end());
    }

    inline const vec_basic &get_container() const
    {
        return diag_;
    }
};

RCP<const MatrixExpr> diagonal_matrix(const vec_basic &container);

class Trace : public Basic
{
private:
    RCP<const Basic> arg_;

public:
    Trace(const RCP<const MatrixExpr> &arg) : arg_(arg)
    {
        SYMENGINE_ASSIGN_TYPEID();
    }

    IMPLEMENT_TYPEID(SYMENGINE_TRACE)
    hash_t __hash__() const override;
    bool __eq__(const Basic &o) const override;
    int compare(const Basic &o) const override;
    vec_basic get_args() const override;
};

RCP<const Basic> trace(const RCP<const MatrixExpr> &arg);

class MatrixAdd : public MatrixExpr
{
private:
    vec_basic terms_;

public:
    MatrixAdd(const vec_basic &terms) : terms_(terms)
    {
        SYMENGINE_ASSIGN_TYPEID();
        SYMENGINE_ASSERT(is_canonical(terms));
    }

    IMPLEMENT_TYPEID(SYMENGINE_MATRIXADD)
    hash_t __hash__() const override;
    bool __eq__(const Basic &o) const override;
    int compare(const Basic &o) const override;
    bool is_canonical(const vec_basic terms) const;
    vec_basic get_args() const override
    {
        return vec_basic(terms_.begin(), terms_.end());
    }
};

RCP<const MatrixExpr> matrix_add(const vec_basic &terms);

std::pair<RCP<const Basic>, RCP<const Basic>> size(const MatrixExpr &m);
tribool is_zero(const MatrixExpr &m);
tribool is_real(const MatrixExpr &m);
tribool is_symmetric(const MatrixExpr &m);
tribool is_square(const MatrixExpr &m);
tribool is_diagonal(const MatrixExpr &m);
tribool is_lower(const MatrixExpr &m);
tribool is_upper(const MatrixExpr &m);
tribool is_toeplitz(const MatrixExpr &m);

} // namespace SymEngine

#endif
