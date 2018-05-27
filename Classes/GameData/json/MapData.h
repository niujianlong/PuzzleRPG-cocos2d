#ifndef __MAP_DATA__
#define __MAP_DATA__

#include "cocos2d.h"
#include "CharData.h"

#define ENEMY_MAX     15    // １ステージで登場出来る敵の最大数
#define DROP_CHAR_MAX 15    // １ステージでドロップ出来るキャラの最大数

class MapData
{
private:
    MapData();   //コンストラクタ
    static MapData* m_instance;
    
    // マップ情報の設定リスト
    struct MapDataParams {
        int mapId;
        std::string mapName;
        int mapStamina;
        int mapEnemy[ENEMY_MAX];
        int mapStage;
        int mapDropChar[DROP_CHAR_MAX];
        int mapDropCoin;
        bool mapBoss;
    };
    static std::map<int, MapDataParams> m_mapDataList;
    
    // マップ管理ファイルのファイルパス
    CC_SYNTHESIZE(std::string, m_mapListFile, MapListFile);
    
public:
    ~MapData();
    static MapData* getInstance();
    static void deleteInstance();
    
    bool mapDataJsonOpen(const std::string& filename);
    
    static MapDataParams getMapData(int dataId){ return m_mapDataList[dataId]; }
};

#endif /* defined(__MAP_DATA__) */
