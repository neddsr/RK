#include <gtest/gtest.h>
#include "EnemyPool.h"

TEST(EnemyPoolTest, CreateAndAnimate) {
    EnemyPool pool;
    
    for (int i = 0; i < 5; ++i) {
        pool.create();
    }
    
    EXPECT_NO_THROW(pool.animate());
}

TEST(EnemyPoolTest, ReuseDeadSpiders) {
    EnemyPool pool;
    
    for (int i = 0; i < 5; ++i) {
        pool.create();
    }
    pool.animate();
    
    for (int i = 0; i < 5; ++i) {
        EXPECT_NO_THROW(pool.create());
    }
}
