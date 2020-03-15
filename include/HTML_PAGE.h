#ifndef _HTML_PAGE_h
#define _HTML_PAGE_h

const char HTML_PAGE[] = "<html lang='en'>\
<head>\
    <meta http-equiv='Content-Type' content='text/html'>\
    <title>Esp8266GSM Settings</title>\
    <style>\
        body {\
            background-color:#8DA1BF;\
            color:#4B5056;\
        }\
        .tabs {\
            position:relative;\
            margin:0;\
            padding:15px;\
            font-size:0\
        }\
        .tabs li {\
            display:inline-block;\
            margin-right:1px;\
            list-style-type:none;\
            font-size:16px\
        }\
        .tabs li:last-child {\
            margin-right:0\
        }\
        .tabs li a {\
            display:block;\
            padding:10px 15px;\
            background:#8DA1BF;\
            text-decoration:none;\
            color:#4b5056;\
            transition:background .5s ease\
        }\
        .tabs a + div {\
            position:absolute;\
            left:0;\
            height:0;\
            padding:0 15px;\
            overflow:hidden\
        }\
        .tabs :target a {\
            background:#afcae8;\
        }\
        .tabs :target a + div {\
            height:100%;\
            overflow:visible\
        }\
        .textField {\
            box-shadow:inset 0 1px 3px rgba(0, 0, 0, 2);\
            border:1px solid #ccc;\
            color:#007e19;\
            width:10em;\
            font-weight:bold;\
            background-color:#8DA1BF;\
            display:block;\
            margin:1px 0 5px 0;\
        }\
        label {\
            font-size:16px;\
            display:block;\
        }\
        td {\
            padding:30px;\
            width:10em;\
        }\
        .btns {\
            background-color:#8DA1BF;\
            border:none;\
            color:#4B5056;\
            padding:10px 50px;\
            text-align:center;\
            text-decoration:none;\
            display:inline-block;\
            font-weight:bold;\
            font-size:18px;\
            -webkit-transition-duration:0.4s;\
            transition-duration:0.3s;\
            cursor:pointer;\
            position:absolute;\
        }\
        .btns:hover {\
            background-color:#afcae8;\
            color:#4B5056;\
        }\
        @media (max-width:768px) {\
            .tabs a {\
                width:100%\
            }\
            .tabs a + div {\
                position:static;\
                float:left\
            }\
            .tabs li {\
                display:block;\
                overflow:hidden;\
                margin:0 0 1px\
            }\
        }\
    </style>\
</head>\
<body>\
<div class='main'>\
    <ul class='tabs'>\
        <li id='option0'>\
            <a href='#option0'><b>Network Settings</b></a>\
            <div id='tab1'>\
                <form action='/network'></form>\
            </div>\
        </li>\
        <li id='option1'>\
            <a href='#option1'><b>GSM connection settings</b></a>\
            <div>\
                <form action='/conn'></form>\
            </div>\
        </li>\
        <li id='option2'>\
            <a href='#option2'><b>GSM Settings</b></a>\
            <div id='tab2'>\
                <form action='/network'></form>\
            </div>\
        </li>\
    </ul>\
</div>\
<script>\
    let data = {\
        arr:['Mode','Ssid','Pass','Host','Gateway','Recive','Transmit','Phone','Voice', 'USSD'],\
        contSrt:[1,5,7,10],\
        load:function () {\
            fetch('/getData').then(function (response) {\
                if (response.status !== 200) {\
                    console.log('Status Code: ' + response.status);\
                    return;\
                }\
                response.json().then(function (e) {\
                    data.json = e;\
                    data.prepPage(data.json);\
                })\
            });\
        },\
        send:function(){\
            if(!('json' in data)) return;\
            let switchFunc = function(it, i){\
                switch (i) {\
                    case 0:\
                        return document.getElementsByName(it)[0].selectedIndex;\
                    case 5:\
                    case 6:\
                    case 8:\
                        return parseInt(document.getElementsByName(it)[0].value);\
                    default:\
                        return document.getElementsByName(it)[0].value;\
                }\
            };\
            data.arr.forEach(function (item, i) {\
                data.json[i] = switchFunc(item, i);\
                console.log(data.json);\
            });\
            fetch('/saveData', {method:'POST', headers:{'Content-Type': 'application/json'}, body: JSON.stringify(data.json)}).then(function (a) {\
                alert('Settings saved, device reboot started!');\
            })\
        },\
        prepPage:function (json) {\
            Array.prototype.slice.call(document.getElementsByTagName('form')).forEach(function (item, i) {\
                let table = document.createElement('table');\
                let options = json[i] ? '<option>AP</option><option selected>Station</option>': '<option selected>AP</option><option>Station</option>';\
                let td = table.appendChild(document.createElement('td'));\
                for (let ind = data.contSrt[i]; ind < data.contSrt[i + 1]; ind++){\
                    let lb = data.arr[ind];\
                    let val = json[data.arr.indexOf(lb)];\
                    td.insertAdjacentHTML('beforeend', lb+':<input class=\\'textField\\' name=\\''+lb+'\\' type=\\'text\\' value=\\''+val+'\\'>');\
                }\
                if (i == 0) td.insertAdjacentHTML('afterbegin',data.arr[i]+'<select name=\\'Mode\\' class=\\'textField\\'>'+options+'</select>');\
                td = table.appendChild(document.createElement('td'));\
                item.append(table);\
                item.insertAdjacentHTML('beforeend', (function(){\
                    let buttonsData = ['Save','Reset','left','right','data.send()','document.location.reload(true)'];\
                    let btnTag = '';\
                    for (let i = 0; i < 2; i++){\
                        btnTag+='<input type=\\'button\\' class=\\'btns\\' value=\\''+buttonsData[i]+'\\' onclick=\\''+buttonsData[4+i]+'\\' style=\\''+buttonsData[2+i]+':60px\\'>';\
                    }\
                    btnTag+='</div>';\
                    return '<div>'+btnTag;\
                })());\
            });\
        }\
    };\
    setTimeout( 'location=\"#option0\";', 0 );\
    data.load();\
</script>\
</body>\
</html>";

#endif