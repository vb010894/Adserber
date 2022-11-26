package com.vbsoft.adserberserver.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class TestController {


    @GetMapping("/api/test")
    public String test() {
        return "aaa";
    }


}
