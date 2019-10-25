#ifndef _ME_SIMILAR_H
#define _ME_SIMILAR_H

ME_NAMESPACE_BEGIN

ME_CLASS_PREPARE(Similar)

interface ISimilar
{

};

class Similar: public Project, public ISimilar
{
    ME_CLASS_DECL(Similar)

public:

    explicit Similar(Magdle& env);
    ~Similar();

};

ME_NAMESPACE_END

#endif
