class Solution(object):
    def reformatDate(self, date):
        day, month, year = date.split()

        day = day[:-2].zfill(2)

        months = {
            "Jan": "01", "Feb": "02", "Mar": "03", "Apr": "04",
            "May": "05", "Jun": "06", "Jul": "07", "Aug": "08",
            "Sep": "09", "Oct": "10", "Nov": "11", "Dec": "12"
        }

        return year + "-" + months[month] + "-" + day
