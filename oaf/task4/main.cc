#include "enumerator.hh"
#include "account_data.hh"
#include "seqinfileenumerator.hh"
#include "procedure.hh"
#include <iostream>
#include <map>

class AccountResults : public Enumerator<AccountData>
{
public:
    virtual void first() { resultIterator = results.begin(); }
    virtual void next() { ++resultIterator; }
    virtual bool end() const { return resultIterator == results.end(); }
    virtual AccountData current() const;

    int& operator[](const std::string& index)
    {
        return results[index];
    }

private:
    std::map<std::string, int> results;
    std::map<std::string, int>::iterator resultIterator;
};

AccountData AccountResults::current() const
{
    AccountData data;
    data.accountId = resultIterator->first;
    data.value = resultIterator->second;
    return data;
}

class ResultPrinter : public Procedure<AccountData>
{
public:
    virtual void init() {}
    virtual void body(const AccountData& current);
};

void ResultPrinter::body(const AccountData& current)
{
    std::cout << current.accountId << " " << current.value << std::endl;
}

class ResultCalculationProcedure: public Procedure<AccountData>
{
public:
    virtual void init();
    virtual void body(const AccountData& current);
    void printResult();
private:
    AccountResults results;
};

void ResultCalculationProcedure::init()
{
}

void ResultCalculationProcedure::body(const AccountData& current)
{
    results[current.accountId] += current.value;
}

void ResultCalculationProcedure::printResult()
{
    ResultPrinter rp;
    rp.addEnumerator(&results);
    rp.run();
}

int main(int argc, char* argv[])
{
    SeqInFileEnumerator<AccountData> fit("account.txt");
    ResultCalculationProcedure pr;
    pr.addEnumerator(&fit);
    pr.run();
    pr.printResult();
    return 0;
}
