#include <CircularBuffer.hpp>
#include <catch.hpp>

TEST_CASE("Push-pop")
{
    CircularBuffer buff(5);

    SECTION("Check Buffer Size")
    {
        REQUIRE(buff.size() == 5);
    }

    SECTION("Normal Push-pop")
    {
        uint8_t data[5] = {11, 12, 13, 14, 15};

        for(uint8_t i = 0; i < sizeof(data); i++)
        {
            REQUIRE(buff.push(data[i]));
            REQUIRE(buff.count() == i+1);
        }

        uint8_t popdata = 212;

        for(uint8_t i = 0; i < sizeof(data); i++)
        {
            REQUIRE(buff.pop(&popdata));
            REQUIRE(popdata == data[i]);
            REQUIRE(buff.count() == buff.size() - i - 1);
        }
    }

    SECTION("Push Full")
    {
        for(uint8_t i = 0; i < buff.size(); i++)
        {
            REQUIRE(buff.push(i));
            REQUIRE(buff.count() == i+1);
        }

        REQUIRE(!buff.push(123));
    }

    SECTION("Pop Empty")
    {
        uint8_t popdata = 212;
        REQUIRE(!buff.pop(&popdata));
    }

    SECTION("Clearing buffer")
    {
        uint8_t data[5] = {11, 12, 13, 14, 15};

        //fill until full
        for(uint8_t i = 0; i < sizeof(data); i++)
        {
            REQUIRE(buff.push(data[i]));
            REQUIRE(buff.count() == i+1);
        }

        buff.clear();
        REQUIRE(buff.count() == 0);
        uint8_t popdata = 212;
        REQUIRE(!buff.pop(&popdata));
        REQUIRE(buff.push(popdata));
    }

    SECTION("Head & Tail Moving Past Buffer Size")
    {
        uint8_t popData = 212;
        uint8_t pushSize = 5;
        uint8_t popSize = 3;
        uint8_t lastPushData = 1;
        uint8_t lastPopData = lastPushData;
        uint32_t correctCount = 0;

        for(uint8_t iter = 0; iter < 2; iter++)
        {
            for(uint8_t i = 0; i < pushSize; i++)
            {
                REQUIRE(buff.push(lastPushData));
                lastPushData++;
                correctCount++;

                REQUIRE(buff.count() == correctCount);
            }

            for(uint8_t i = 0; i < popSize; i++)
            {
                REQUIRE(buff.pop(&popData));
                REQUIRE(popData == lastPopData);
                lastPopData++;
                correctCount--;

                REQUIRE(buff.count() == correctCount);
            }

            pushSize = popSize;
        }
    }
}
