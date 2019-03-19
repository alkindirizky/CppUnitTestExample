#include <SerialProcessor.hpp>
#include <catch.hpp>

TEST_CASE("Uint32")
{
    uint8_t data[4] = {0xFA, 0xFB, 0xFC, 0x30};
    uint32_t uintdata = byteUint32((data));
    REQUIRE(uintdata == 0x30FCFBFA);
}

TEST_CASE("Float")
{
    uint8_t data[4];
    float floatdata = 0;

    SECTION("Value 1")
    {
        data[0] = 0x00;
        data[1] = 0x00;
        data[2] = 0x78;
        data[3] = 0x41;
        floatdata = byteFloat(data);

        REQUIRE(floatdata == Approx(15.5));
    }

    SECTION("Value 2")
    {
        data[0] = 0xfa;
        data[1] = 0x3e;
        data[2] = 0xc8;
        data[3] = 0xc2;
        floatdata = byteFloat(data);

        REQUIRE(floatdata == Approx(-100.123));
    }
}
