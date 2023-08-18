#include <cassert>
#include <vector>
#include <ctime>
using namespace std;

namespace utils
{
    namespace
    {
        static constexpr long long nanoseconds = 1'000'000'000;
    }
    int get_hours_from_timestamp(long long timestamp) { return (timestamp / nanoseconds / 60 / 60) % 24; }
    int get_minutes_from_timestamp(long long timestamp) { return (timestamp / nanoseconds / 60) % 60; }
    int get_seconds_from_timestamp(long long timestamp) { return (timestamp / nanoseconds) % 60; }
    // Function to get the date from the timestamp
    void get_date_from_timestamp(long long timestamp, int &year, int &month, int &day)
    {
        time_t timestamp_seconds = timestamp / nanoseconds;
        tm *timeinfo = localtime(&timestamp_seconds);
        year = timeinfo->tm_year + 1900; // Years since 1900
        month = timeinfo->tm_mon + 1;    // Months since January (0-11)
        day = timeinfo->tm_mday;         // Day of the month (1-31)
    }
}

int validate_timestamp_matrix(std::vector<long long> timestamps,
                              std::vector<std::vector<long long>> matrix)
{
    int num_columns = matrix[0].size();
    int num_rows = matrix.size();
    int timestamp_sz = timestamps.size();

    assert(timestamps.size() == matrix.size());

    for (auto n = 0; n < num_rows; n++)
    {
        int row_size_curr = matrix[n].size();
        if (row_size_curr != num_columns)
            return false;

        auto hour = utils::get_hours_from_timestamp(timestamps[n]);
        auto minute = utils::get_minutes_from_timestamp(timestamps[n]);
        auto second = utils::get_seconds_from_timestamp(timestamps[n]);
        int year, month, day;
        utils ::get_date_from_timestamp(timestamps[n], year, month, day);
        for (auto m = 0; m < num_columns; m++)
        {
            auto timestamp = matrix[n][m];
            auto cur_h = utils::get_hours_from_timestamp(timestamp);
            auto cur_m = utils::get_minutes_from_timestamp(timestamp);
            auto cur_s = utils::get_seconds_from_timestamp(timestamp);
            int cur_year, cur_month , cur_day;
            utils ::get_date_from_timestamp(timestamp, cur_year, cur_month, cur_day);
            if (cur_year != year || cur_month != month || cur_day != day ||cur_s != second)
                return false;
        }
    }
    return true;
}

int main()
{
    vector<long long> timestamps = {
        1534603824709837829,
        1621950025329781281,
        1114528804861354169,
        1225006421755512038,
        1117311719945796256,
    };
    vector<vector<long long>> matrix = {
        {
            1526309424948447390,
            1528987824837906125,
            1534085424832901789,
            1542379824078311506,
            1529506224732644596,
            1542811824022872268,
        },
        {
            1615815625513463622,
            1628343625289343613,
            1623505225766168286,
            1626788425304068545,
            1626529225646246305,
            1617889225768036679,
        },
        {
            1111072804181840707,
            1117984804950760384,
            1118676004816011858,
            1112455204274534243,
            1107962404402873419,
            1114269604442822504,
        },
        {
            1230104021185237028,
            1220686421253645018,
            1232609621692287696,
            1222068821294661901,
            1227166421080065210,
            1233300821359065678,
        },
        {
            1117657319768565753,
            1123359719131749475,
            1117570919124768817,
            1121372519603188958,
            1115583719900781659,
            1117138919871586170,
        },
    };
    assert(validate_timestamp_matrix(timestamps, matrix));
    return 0;
}