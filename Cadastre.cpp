#include "Cadastre.h"

CIterator::CIterator(const string& region,
                     unsigned int id,
                     const string& city,
                     const string& owner,
                     const string& addr) : m_Region(region),m_ID(id), m_City(city), m_Address(addr), m_Owner(owner) {}

bool CIterator::EqualCA(const string& city, const string& addr) const
{
    return m_City == city && m_Address == addr;
}
bool CIterator::EqualRID(const string& region, unsigned int id) const
{
    return m_Region == region && m_ID == id;
}

void CIterator::Print() const
{
    cout << m_City << m_Address << m_Region << m_ID;
}

CLandRegister::CLandRegister() {}

bool CLandRegister::add(const string& city, const string& addr, const string& region, unsigned int id)
{
    if (std::any_of(m_List.begin(), m_List.end(),
                    [&](const CIterator& prop) {
                        return prop.EqualCA(city, addr);
                    })) {
        return false;  // Property with similar characteristics already exists
    }

    // Check if there are properties with the same region and ID
    if (std::any_of(m_List.begin(), m_List.end(),
                    [&](const CIterator& prop) {
                        return prop.EqualRID(region, id);
                    })) {
        return false;  // Property with similar characteristics already exists
    }

    // No matches found, add the property to the vector
    CIterator prop(region, id, city, addr);
    m_List.push_back(prop);
    return true;  // Property added successfully
}

void CLandRegister::PrintAll() const
{
    for(const auto& property : m_List)
    {
        property.Print();
        cout << endl;
    }
}


