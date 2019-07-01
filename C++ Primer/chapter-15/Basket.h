#include <bits/stdc++.h>
#include "Quote.h"

class Basket
{
    static bool compare(const std::shared_ptr<Quote> rhs, const std::shared_ptr<Quote> lhs)
    {
        return rhs->isbn() < lhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
public:
    void add_item(const std::shared_ptr<Quote> &sale) 
    {
        items.insert(sale);
    }
    void add_item(const Quote &q)
    {
        items.insert(std::shared_ptr<Quote>(q.clone()));
    }
    void add_item(Quote &&q)
    {
        items.insert(std::shared_ptr<Quote>(std::move(q).clone()));
    }
    double total_receipt(std::ostream &os) const;
};