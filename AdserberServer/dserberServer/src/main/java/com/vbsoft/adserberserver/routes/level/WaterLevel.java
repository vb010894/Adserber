package com.vbsoft.adserberserver.routes.level;

import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component("level")
@Scope(BeanDefinition.SCOPE_PROTOTYPE)
public class WaterLevel extends VerticalLayout {
}
