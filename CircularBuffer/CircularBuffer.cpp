#include <CircularBuffer.hpp>

CircularBuffer::CircularBuffer(uint32_t buffsize)
{
    m_buff = new uint8_t[buffsize];
    m_size = buffsize;
    clear();
}

CircularBuffer::~CircularBuffer()
{
    delete m_buff;
}

void CircularBuffer::clear()
{
    m_head = 0;
    m_tail = 0;
    m_count = 0;
}

uint32_t CircularBuffer::size()
{
    return m_size;
}

uint32_t CircularBuffer::count()
{
    return m_count;
}

bool CircularBuffer::push(uint8_t inputValue)
{
    if(m_count == m_size)
    {
        return false;
    }

    m_buff[m_head] = inputValue;
    m_head = (m_head + 1) % m_size;
    m_count++;

    return true;
}

bool CircularBuffer::pop(uint8_t* outputValue)
{
    if(m_count == 0)
    {
        return false;
    }

    *outputValue = m_buff[m_tail];
    m_tail = (m_tail + 1) % m_size;
    m_count--;

    return true;
}
