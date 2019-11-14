#ifndef _ME_APP_H
#define _ME_APP_H

ME_NAMESPACE_BEGIN

class App {
public:
    virtual int exec() = 0;
};

class CmdApp : public App {
public:

    int exec() override;
};

ME_NAMESPACE_END

#endif
