#include "CDateTime.h"
#include "..\DateTimeSpan\CDateTimeSpan.h"

using namespace GeyserEruptionCalc;

CDateTime::CDateTime() :
	m_date(),
	m_time()
{
}

CDateTime::CDateTime(const CDateTime &Ref) :
	m_date(Ref.m_date),
	m_time(Ref.m_time)
{
}

CDateTime::CDateTime(const CDate &date, const CTime &time, bool IsDST) :
	m_date(date),
	m_time(time)
{
	if(IsDST)
		this->operator-=(CHours(1));
}

CDateTime::~CDateTime()
{
}

const CDateTime& CDateTime::operator=(const CDateTime &Ref)
{
	m_date = Ref.m_date;
	m_time = Ref.m_time;
	return *this;
}

void CDateTime::SetDate(const CDate &date)
{
	m_date = date;
}

void CDateTime::SetTime(const CTime &time)
{
	m_time = time;
}

const CDate& CDateTime::GetDate() const
{
	CheckValidDateTimeWithThrows();
	return m_date;
}

const CTime& CDateTime::GetTime() const
{
	CheckValidDateTimeWithThrows();
	return m_time;
}

void CDateTime::AddDays(long days)
{
	CheckValidDateTimeWithThrows();
	this->operator+=(CDays(days));
}

void CDateTime::AddMonths(long months)
{
	CheckValidDateTimeWithThrows();
	this->operator+=(CDays(months));
}

void CDateTime::AddHours(long hours)
{
	CheckValidDateTimeWithThrows();
	this->operator+=(CDays(hours));
}

const CDateTime CDateTime::DSTStart(const CYear &year)
{
	long y = year.GetYear();
	if(y >= 1967 && y < 1974)
	{
		CDateTime tmptd;
		tmptd = LastDayOfWeekInMonth(CYear(y), CMonth(4), ESUNDAY);
		tmptd.m_time.SetHour(2);
		return CDateTime(tmptd);
	}
	else if(y == 1974)
	{
		return CDateTime(CDate(CYear(1974),CMonth(1),CDay(6)), CTime(2,0,0));
	}
	else if(y == 1975)
	{
		return CDateTime(CDate(CYear(1975),CMonth(2),CDay(23)), CTime(2,0,0));
	}
	else if(y >= 1976 && y < 1986)
	{
		CDateTime tmptd;
		tmptd = LastDayOfWeekInMonth(CYear(y), CMonth(4), ESUNDAY);
		tmptd.m_time.SetHour(2);
		return CDateTime(tmptd);
	}
	else if(y >= 1986 && y < 2007)
	{
		CDateTime tmptd;
		tmptd = NthDayOfWeek(CYear(y), CMonth(4), ESUNDAY, 1);
		tmptd.m_time.SetHour(2);
		return CDateTime(tmptd);
	}
	else if(y >= 2007)
	{
		CDateTime tmptd;
		tmptd = NthDayOfWeek(CYear(y), CMonth(3), ESUNDAY, 2);
		tmptd.m_time.SetHour(2);
		return CDateTime(tmptd);
	}
	else
	{
		return CDateTime();
	}
}

const CDateTime CDateTime::DSTEnd(const CYear &year)
{
	long y = year.GetYear();
	if(y >= 1967 && y < 1974)
	{
		CDateTime tmptd;
		tmptd = LastDayOfWeekInMonth(CYear(y), CMonth(10), ESUNDAY);
		tmptd.m_time.SetHour(2);
		return CDateTime(tmptd);
	}
	else if(y == 1974)
	{
		return CDateTime(CDate(CYear(1974),CMonth(10),CDay(27)),CTime(2,0,0));
	}
	else if(y >= 1975 && y < 2007)
	{
		CDateTime tmptd;
		tmptd = LastDayOfWeekInMonth(CYear(y), CMonth(10), ESUNDAY);
		tmptd.m_time.SetHour(2);
		return CDateTime(tmptd);
	}
	else if(y >= 2007)
	{
		CDateTime tmptd;
		tmptd = NthDayOfWeek(CYear(y), CMonth(11), ESUNDAY, 1);
		tmptd.m_time.SetHour(2);
		return CDateTime(tmptd);
	}
	else
	{
		return CDateTime();
	}
}

const CDateTime CDateTime::NthDayOfWeek(const CYear &year, const CMonth &month, DAYOFWEEK weekday, int n)
{
	CDateTime tmpdt(CDate(year,month,1), CTime(0,0,0));

	DAYOFWEEK firstdayinmonth = CDate::GetDayOfWeek(tmpdt.GetDate());
	//Calc to first day of desired weekday
	long n2;
	n2 = weekday - firstdayinmonth;
	n2 = n2 % 7;

	long tmpd=1;
	tmpd += n2;
	n--;
	while(n > 0 && tmpd < tmpdt.GetDate().GetDaysInMonth())
	{
		tmpd+=7;
		n--;
	}
	tmpdt.m_date.SetDay(tmpd);
	return CDateTime(tmpdt);
}

const CDateTime CDateTime::LastDayOfWeekInMonth(const CYear &year, const CMonth &month, DAYOFWEEK weekday)
{
	CDateTime tmpdt = NthDayOfWeek(year,month,weekday,1);
	long dinm = tmpdt.m_date.GetDaysInMonth();
	long d = tmpdt.m_date.GetDay().GetDay();
	while(d <= dinm)
		d+=7;
	tmpdt.m_date.SetDay(d);
	return CDateTime(tmpdt);
}

/*const CDateTime CDateTime::SunRise() const
{
	CheckValidDateTimeWithThrows();
}

const CDateTime CDateTime::SunSet() const
{
	CheckValidDateTimeWithThrows();
}

const CDateTime CDateTime::MoonRise() const
{
	CheckValidDateTimeWithThrows();
}

const CDateTime CDateTime::MoonSet() const
{
	CheckValidDateTimeWithThrows();
}*/

bool CDateTime::operator==(const CDateTime &Ref) const
{
	CheckValidDateTimeWithThrows();
	if(m_date == Ref.m_date && m_time == Ref.m_time)
		return true;
	return false;
}

bool CDateTime::operator!=(const CDateTime &Ref) const
{
	CheckValidDateTimeWithThrows();
	return !((*this)==Ref);
}

bool CDateTime::operator<(const CDateTime &Ref) const
{
	CheckValidDateTimeWithThrows();
	if((*this)==Ref)
		return false;
	if(m_date < Ref.m_date)
		return true;
	if(m_date == Ref.m_date)
	{
		if(m_time < Ref.m_time)
			return true;
	}
	return false;
}

bool CDateTime::operator>(const CDateTime &Ref) const
{
	CheckValidDateTimeWithThrows();
	if((*this)==Ref)
		return false;
	return !((*this)<Ref);
}

bool CDateTime::operator>=(const CDateTime &Ref) const
{
	CheckValidDateTimeWithThrows();
	if((*this)==Ref)
		return true;
	return (*this)>Ref;
}

bool CDateTime::operator<=(const CDateTime &Ref) const
{
	CheckValidDateTimeWithThrows();
	if((*this)==Ref)
		return true;
	return (*this)<Ref;
}

const CDateTimeSpan CDateTime::operator-(const CDateTime &Ref) const
{
	CheckValidDateTimeWithThrows();
	if(Ref > (*this))
	{
		CDateTimeSpan t = Ref - (*this);
		long long s = t.GetSpan();
		t.SetSpan(-s);
		return CDateTimeSpan(t);
	}
	else
	{
		long long tot = 0;
		long tm = 0;
		CDateTime tmp1(*this);
		CDateTime tmp2(Ref);

		//Calculat second portion first
		if(tmp2.GetTime().GetSecond().GetSecond() > tmp1.GetTime().GetSecond().GetSecond())
		{
			tmp1 -= CMinutes(1);
			tot  += (60+tmp1.GetTime().GetSecond().GetSecond())-tmp2.GetTime().GetSecond().GetSecond();
		}
		else
		{
			tot += tmp1.GetTime().GetSecond().GetSecond()-tmp2.GetTime().GetSecond().GetSecond();
		}

		//Calculate minute difference
		if(tmp2.GetTime().GetMinute().GetMinute() > tmp1.GetTime().GetMinute().GetMinute())
		{
			tmp1 -= CHours(1);
			tot  += 60*((60+tmp1.GetTime().GetMinute().GetMinute())-tmp2.GetTime().GetMinute().GetMinute());
		}
		else
		{
			tot  += 60*(tmp1.GetTime().GetMinute().GetMinute()-tmp2.GetTime().GetMinute().GetMinute());
		}

		//Calculate hour difference
		if(tmp2.GetTime().GetHour().GetHour() > tmp1.GetTime().GetHour().GetHour())
		{
			tmp1 -= CDays(1);
			tot  += 3600*((24+tmp1.GetTime().GetHour().GetHour())-tmp2.GetTime().GetHour().GetHour());
		}
		else
		{
			tot  += 3600*(tmp1.GetTime().GetHour().GetHour()-tmp2.GetTime().GetHour().GetHour());
		}

		//Calculate Day Difference
		if(tmp1.m_date < tmp2.m_date)
			throw new CDateTimeException();

		while(tmp1.m_date != tmp2.m_date)
		{
			tmp1 -= CDays(1);
			tot  += 86400;
		}
		return CDateTimeSpan(tot);
	}
}

const CDateTime CDateTime::operator+(const CDateTimeSpan &Ref) const
{
	CheckValidDateTimeWithThrows();
	CDateTime tmp(*this);
	CSeconds v(Ref.GetSpan());
	tmp += v;
	return CDateTime(tmp);
}

const CDateTime CDateTime::operator-(const CDateTimeSpan &Ref) const
{
	CheckValidDateTimeWithThrows();
	CDateTime tmp(*this);
	CSeconds v(Ref.GetSpan());
	tmp -= v;
	return CDateTime(tmp);
}

const CDateTime& CDateTime::operator+=(const CDateTimeSpan &Ref)
{
	CheckValidDateTimeWithThrows();
	return this->operator+=(CSeconds(Ref.GetSpan()));
}

const CDateTime& CDateTime::operator-=(const CDateTimeSpan &Ref)
{
	CheckValidDateTimeWithThrows();
	return this->operator-=(CSeconds(Ref.GetSpan()));
}

const CDateTime CDateTime::operator+(const CDays &Ref) const
{
	CheckValidDateTimeWithThrows();
	if(Ref.GetDays() < 0)
	{
		CDays tmp(-Ref.GetDays());
		return this->operator-(tmp);
	}
	if(Ref.GetDays() == 0)
		return CDateTime(*this);
	CDateTime tmp(*this);
	long d = Ref.GetDays();
	long dinm;

	while(d > 0)
	{
		dinm = tmp.GetDate().GetDaysInMonth();
		if((d+tmp.GetDate().GetDay().GetDay()) > dinm)
		{
			d--;
			d-=(dinm-tmp.GetDate().GetDay().GetDay());
			tmp.IncMonth();
		}
		else
		{
			tmp.m_date.SetDay(tmp.GetDate().GetDay().GetDay() + d);
			d-=d;
		}
	}
	return CDateTime(tmp);
}

const CDateTime CDateTime::operator-(const CDays &Ref) const
{
	CheckValidDateTimeWithThrows();
	if(Ref.GetDays() < 0)
	{
		CDays tmp(-Ref.GetDays());
		return this->operator+(tmp);
	}
	if(Ref.GetDays() == 0)
		return CDateTime(*this);

	CDateTime tmp(*this);
	long d = Ref.GetDays();
	long curd;

	while(d > 0)
	{
		curd = tmp.m_date.GetDay().GetDay();
		if(d >= curd)
		{
			tmp.DecMonth();
			d -= curd;
		}
		else
		{
			tmp.m_date.SetDay(curd-d);
			d -= d;
		}
	}
	return CDateTime(tmp);
}

const CDateTime& CDateTime::operator+=(const CDays &Ref)
{
	CheckValidDateTimeWithThrows();
	if(Ref.GetDays() < 0)
	{
		return this->operator-=(CDays(-Ref.GetDays()));
	}
	if(Ref.GetDays() == 0)
	{
		return *this;
	}

	long d = Ref.GetDays();
	long dinm;

	while(d > 0)
	{
		dinm = m_date.GetDaysInMonth();
		if((d+m_date.GetDay().GetDay()) > dinm)
		{
			d-=1;
			d-=(dinm-m_date.GetDay().GetDay());
			IncMonth();
		}
		else
		{
			m_date.SetDay(m_date.GetDay().GetDay() + d);
			d-=d;
		}
	}
	return *this;
}

const CDateTime& CDateTime::operator-=(const CDays &Ref)
{
	CheckValidDateTimeWithThrows();
	if(Ref.GetDays() < 0)
	{
		return this->operator+=(CDays(-Ref.GetDays()));
	}
	if(Ref.GetDays() == 0)
	{
		return *this;
	}

	long d = Ref.GetDays();
	long curd;

	while(d > 0)
	{
		curd = m_date.GetDay().GetDay();
		if(d >= curd)
		{
			DecMonth();
			d -= curd;
		}
		else
		{
			m_date.SetDay(curd-d);
			d -= d;
		}
	}
	return *this;
}

const CDateTime CDateTime::operator+(const CHours &Ref) const
{
	CheckValidDateTimeWithThrows();
	long h = Ref.GetHours();
	if(h < 0)
	{
		return this->operator-(CHours(-h));
	}
	if(h==0)
		return CDateTime(*this);

	CDateTime tmp(*this);
	long d=0;
	if(h >= 24)
	{
		d = (long)(h/24);
		h = h%24;
	}

	if( (m_time.GetHour().GetHour() + h) >= 24)
	{
		d++;
		tmp+=CDays(d);
		h = (h - (24-m_time.GetHour().GetHour()));
		tmp.m_time.SetHour(h);
		return CDateTime(tmp);
	}
	else
	{
		if(d > 0)
			tmp+=CDays(d);
		tmp.m_time.SetHour(h+m_time.GetHour().GetHour());
		return CDateTime(tmp);
	}
}

const CDateTime CDateTime::operator-(const CHours &Ref) const
{
	CheckValidDateTimeWithThrows();
	long h = Ref.GetHours();
	if(h < 0)
	{
		return this->operator-(CHours(-h));
	}
	if(h==0)
		return CDateTime(*this);

	CDateTime tmp(*this);
	long d=0;
	if(h >= 24)
	{
		d = (long)(h/24);
		h = h%24;
	}

	if( h > m_time.GetHour().GetHour() )
	{
		d++;
		tmp-=CDays(d);
		h = m_time.GetHour().GetHour() - h;
		tmp.m_time.SetHour((24-h)%24);
		return CDateTime(tmp);
	}
	else
	{
		if(d > 0)
			tmp-=CDays(d);
		tmp.m_time.SetHour(m_time.GetHour().GetHour()-h);
		return CDateTime(tmp);
	}
}

const CDateTime& CDateTime::operator+=(const CHours &Ref)
{
	CheckValidDateTimeWithThrows();
	long h = Ref.GetHours();
	if(h < 0)
	{
		return this->operator-=(CHours(-h));
	}
	else if(h == 0)
	{
		return *this;
	}
	else
	{
		long d = 0;
		if(h >= 24)
		{
			d = (long)(h/24);
			h = h%24;
		}

		if( (m_time.GetHour().GetHour() + h) >= 24)
		{
			d++;
			this->operator+=(CDays(d));
			h = (h - (24-m_time.GetHour().GetHour()));
			m_time.SetHour(h);
			return *this;
		}
		else
		{
			if(d > 0)
				this->operator+=(CDays(d));
			m_time.SetHour(h+m_time.GetHour().GetHour());
			return *this;
		}
	}
}

const CDateTime& CDateTime::operator-=(const CHours &Ref)
{
	CheckValidDateTimeWithThrows();
	long h = Ref.GetHours();
	if(h < 0)
	{
		return this->operator+=(CHours(-h));
	}
	else if(h == 0)
	{
		return *this;
	}
	else
	{
		long d=0;
		if(h >= 24)
		{
			d = (long)(h/24);
			h = h%24;
		}

		if( h > m_time.GetHour().GetHour())
		{
			d++;
			this->operator-=(CDays(d));
			h = m_time.GetHour().GetHour() - h;
			m_time.SetHour((24-h)%24);
			return *this;
		}
		else
		{
			if(d > 0)
				this->operator-=(CDays(d));
			m_time.SetHour(m_time.GetHour().GetHour()-h);
			return *this;
		}
	}
}

const CDateTime CDateTime::operator+(const CMinutes &Ref) const
{
	CheckValidDateTimeWithThrows();
	long m = Ref.GetMinutes();
	if(m < 0)
	{
		return this->operator-(CMinutes(-m));
	}
	else if(m == 0)
	{
		return CDateTime(*this);
	}
	else
	{
		CDateTime tmp(*this);
		long h=0;
		if(m>=60)
		{
			h = (long)(m/60);
			m = m % 60;
		}

		if( (tmp.m_time.GetMinute().GetMinute() + m) >= 60)
		{
			h++;
			tmp += CHours(h);
			tmp.m_time.SetMinute((tmp.m_time.GetMinute().GetMinute() + m) - 60);
		}
		else
		{
			if(h > 0)
				tmp += CHours(h);
			tmp.m_time.SetMinute(m);
		}
		return CDateTime(tmp);
	}
}

const CDateTime CDateTime::operator-(const CMinutes &Ref) const
{
	CheckValidDateTimeWithThrows();
	long m = Ref.GetMinutes();
	if(m < 0)
	{
		return this->operator+(CMinutes(-m));
	}
	else if(m == 0)
	{
		return CDateTime(*this);
	}
	else
	{
		CDateTime tmp(*this);
		long h=0;
		if(m>=60)
		{
			h = (long)(m/60);
			m = m % 60;
		}

		if( (tmp.m_time.GetMinute().GetMinute() + m) >= 60)
		{
			h++;
			tmp += CHours(h);
			tmp.m_time.SetMinute((tmp.m_time.GetMinute().GetMinute() + m) - 60);
		}
		else
		{
			if(h > 0)
				tmp += CHours(h);
			tmp.m_time.SetMinute(m);
		}
		return CDateTime(tmp);
	}
}

const CDateTime& CDateTime::operator+=(const CMinutes &Ref)
{
	CheckValidDateTimeWithThrows();
	long m = Ref.GetMinutes();
	if(m < 0)
	{
		return this->operator-=(CMinutes(-m));
	}
	else if(m == 0)
	{
		return *this;
	}
	else
	{
		long h=0;
		if(m>=60)
		{
			h = (long)(m/60);
			m = m % 60;
		}

		if( (m_time.GetMinute().GetMinute() + m) >= 60)
		{
			h++;
			*this += CHours(h);
			m_time.SetMinute((m_time.GetMinute().GetMinute() + m) - 60);
		}
		else
		{
			if(h > 0)
				*this += CHours(h);
			m_time.SetMinute(m);
		}
		return *this;
	}
}

const CDateTime& CDateTime::operator-=(const CMinutes &Ref)
{
	CheckValidDateTimeWithThrows();
	long m = Ref.GetMinutes();
	if(m < 0)
	{
		return this->operator+=(CMinutes(-m));
	}
	else if(m == 0)
	{
		return *this;
	}
	else
	{
		long h=0;
		if(m>=60)
		{
			h = (long)(m/60);
			m = m % 60;
		}

		if( (m_time.GetMinute().GetMinute() + m) >= 60)
		{
			h++;
			*this += CHours(h);
			m_time.SetMinute((m_time.GetMinute().GetMinute() + m) - 60);
		}
		else
		{
			if(h > 0)
				*this += CHours(h);
			m_time.SetMinute(m);
		}
		return *this;
	}
}

const CDateTime CDateTime::operator+(const CSeconds &Ref) const
{
	CheckValidDateTimeWithThrows();
	CDateTime tmp(*this);
	tmp += Ref;
	return CDateTime(tmp);
}

const CDateTime CDateTime::operator-(const CSeconds &Ref) const
{
	CheckValidDateTimeWithThrows();
	CDateTime tmp(*this);
	tmp -= Ref;
	return CDateTime(tmp);
}

const CDateTime& CDateTime::operator+=(const CSeconds &Ref)
{
	CheckValidDateTimeWithThrows();
	long long s = Ref.GetSeconds();
	if(s < 0)
	{
		return this->operator-=(CSeconds(-s));
	}
	else if(s == 0)
	{
		return *this;
	}
	else
	{
		long m=0;
		if(s >= 60)
		{
			m = (long)(s/60);
			s = s%60;
		}

		if( (s+m_time.GetSecond().GetSecond()) >= 60)
		{
			m++;
			this->operator+=(CMinutes(m));
			m_time.SetSecond((long)((m_time.GetSecond().GetSecond() + s) - 60));
		}
		else
		{
			if(m>0)
				this->operator+=(CMinutes(m));
			m_time.SetSecond((long)(m_time.GetSecond().GetSecond() + s));
		}
		return *this;
	}
}

const CDateTime& CDateTime::operator-=(const CSeconds &Ref)
{
	CheckValidDateTimeWithThrows();
	long long s = Ref.GetSeconds();
	if(s < 0)
	{
		return this->operator+=(CSeconds(-s));
	}
	else if(s == 0)
	{
		return *this;
	}
	else
	{
		long m=0;
		if(s >= 60)
		{
			m = (long)(s/60);
			s = s%60;
		}

		if(m_time.GetSecond().GetSecond() < s)
		{
			m++;
			s = s - m_time.GetSecond().GetSecond();
			this->operator-=(CMinutes(m));
			m_time.SetSecond((long)(60-s));
		}
		else
		{
			m_time.SetSecond((long)(m_time.GetSecond().GetSecond()-s));
		}
		return *this;
	}
}

bool CDateTime::IsValidDateTime() const
{
	if(m_date.IsValidDate() && m_time.IsValidTime())
		return true;
	return false;
}

void CDateTime::CheckValidDateTimeWithThrows() const
{
	if(!IsValidDateTime())
		throw new CDateTimeException();
}

void CDateTime::IncMonth()
{
	CheckValidDateTimeWithThrows();
	m_date.SetDay(1);
	if(m_date.GetMonth().GetMonth() == 12)
	{
		m_date.SetYear(m_date.GetYear().GetYear()+1);
		m_date.SetMonth(1);
	}
	else
	{
		m_date.SetMonth(m_date.GetMonth().GetMonth()+1);
	}
}

void CDateTime::DecMonth()
{
	CheckValidDateTimeWithThrows();
	if(m_date.GetMonth().GetMonth() == 1)
	{
		m_date.SetYear(m_date.GetYear().GetYear()-1);
		m_date.SetMonth(12);
	}
	else
	{
		m_date.SetMonth(m_date.GetMonth().GetMonth()-1);
	}
	m_date.SetDay(m_date.GetDaysInMonth());
}
