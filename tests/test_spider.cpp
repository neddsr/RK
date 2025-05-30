#include <gtest/gtest.h>
#include "Spider.h"

TEST(SpiderTest, Initialization) {
    Spider spider;
    spider.init("TestSpider", 100.0, 10.0);
    
    EXPECT_TRUE(spider.isAlive());
}

TEST(SpiderTest, DamageTaken) {
    Spider spider;
    spider.init("TestSpider", 50.0, 10.0);
    
    spider.getDamage(30);
    EXPECT_TRUE(spider.isAlive());
    
    spider.getDamage(30);
    EXPECT_FALSE(spider.isAlive());
}
